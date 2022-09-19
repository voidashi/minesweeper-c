/*
 *	Jefferson E. M. Bueno
 *	Nusp: 11275255
 *
 *  Universidade de São Paulo
 *  Instituto de Ciências Matemáticas e de Computação
 *  SCC0201 — Introdução a Ciências da Computação II
 * 
 *	Trabalho 01: Campo Minado
 * 
 */



#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1



//Abertura do arquivo que contém o campo, 
//a partir do nome contido em "nome_arquivo".
FILE* abre_arquivo(FILE* arquivo){

    char nome_arquivo[8];      //nome do arquivo (x.board)
    scanf("%s", nome_arquivo);

    arquivo = fopen(nome_arquivo, "r");

    return arquivo;
}



//Descobre o número de linhas e colunas na matriz presente no arquivo
//Após isso, volta  o ponteiro ao começo do arquivo.
void descobre_lin_col(FILE* arquivo, int* lin, int* col){

    char prov;      //Variavel provisória para armazenar os caracteres da matriz.
    int cont = 0;   //Variavel para contar o número total de caracteres.
    while(fscanf(arquivo, "%c", &prov) != EOF){
        
        cont++;
        if(prov == '\n'){   //Caso encontre um '\n', soma uma linha.
            (*lin)++;
        }
    }
    *col = cont / *lin; //O numero de colunas é igual ao total de valores dividido pelas linhas
    fseek(arquivo, 0, SEEK_SET);
    
}



//Aloca dinamicamente a matriz a partir do tamanho das linhas e colunas
//obtido pela função "descobre_lin_col".
char** aloca_matriz(int lin, int col){
    
    char** mat = (char**)malloc(lin * sizeof(char*));
    for(int i = 0; i < lin; i++){

        mat[i] = (char*)malloc(col * sizeof(char));
    }

	return mat;
}



//Lê a matriz do campo minado presente no arquivo
//E a armazena em "mat_campo".
void le_matriz_campo(FILE* arquivo, char** mat_campo, int lin, int col){
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            fscanf(arquivo, "%c", &mat_campo[i][j]);
        }
    }
}



//Printa a matriz iterativamente.
void printa_matriz(char** mat, int lin, int col){

	for(int i = 0; i < lin; i++){
	    for(int j = 0; j < col-1; j++){

            printf("%c", mat[i][j]);
	    }
        printf("\n");
	}
}



//Retorna verdadeiro caso a coordenada (x, y)
//seja valida, ou seja, esta dentro da matriz
int cord_valida(int x, int y, int lin, int col){

    return (x >= 0) && (x < lin) && (y >= 0) && (y < col-1);
}

//Retorna verdadeiro caso a coordenada (x, y)
//tenha uma bomba (*).
int tem_bomba(int x, int y, char** mat){

    if (mat[x][y] == '*')return 1;
    else return 0;
}

//Conta o numero de bombas nas posicoes vizinhas a coordenada atual (x, y)
//Inicialmente testa se a coordenada está dentro da matriz com cord_valida
//Apos isso, checa se cada uma das 8 posicoes adjacentes contem bombas
//e soma cada uma encontrada a variavel cont.
char conta_bombas_adjacentes(char** mat_campo, int x, int y, int lin, int col){
 
    int cont = 0;

    //Checa a coordenada para cima
    if (cord_valida(x-1, y, lin, col) == 1){
        if (tem_bomba(x-1, y, mat_campo) == 1)cont++;
    }
    //Checa a coordenada para baixo
    if (cord_valida(x+1, y, lin, col) == 1){
        if (tem_bomba(x+1, y, mat_campo) == 1)cont++;
    }
    //Checa a coordenada para a direita
    if (cord_valida(x, y+1, lin, col) == 1){
        if (tem_bomba(x, y+1, mat_campo) == 1)cont++;
    }
    //Checa a coordenada para a esquerda
    if (cord_valida(x, y-1, lin, col) == 1){
        if (tem_bomba(x, y-1, mat_campo) == 1)cont++;
    }
    //Checa a coordenada para cima-direita
    if (cord_valida(x-1, y+1, lin, col) == 1){
        if (tem_bomba(x-1, y+1, mat_campo) == 1)cont++;
    }
    //Checa a coordenada para cima-esquerda
    if (cord_valida(x-1, y-1, lin, col) == 1){
        if (tem_bomba(x-1, y-1, mat_campo) == 1)cont++;
    }
    //Checa a coordenada para baixo-direita
    if (cord_valida(x+1, y+1, lin, col) == 1){
        if (tem_bomba(x+1, y+1, mat_campo) == 1)cont++;
    }
    //Checa a coordenada para baixo-esquerda
    if (cord_valida(x+1, y-1, lin, col) == 1){
        if (tem_bomba(x+1, y-1, mat_campo) == 1)cont++;
    }

    //converter o número de bombas (em inteiro)
    //para o valor correspondente em char
    cont = cont + '0';

    return cont;
}

//Percorre a matriz do campo minado iterativamente, preenchendo
//as posicoes que correspondem a vizinhanca com o numero de bombas
//adjacentes, utilizando a funcao conta_combas_adjacentes
void preenche_matriz_dicas(char** mat_campo, int lin, int col){

	for(int i = 0; i < lin; i++){
	    for(int j = 0; j < col; j++){

            char cont = conta_bombas_adjacentes(mat_campo, i, j, lin, col);

            if((cont != '0') && (mat_campo[i][j] != '*')){ //caso existam bombas, adiciona seu valor.
                mat_campo[i][j] = cont;
            }          
	    }
	}
}



//Preenche a matriz do usuario com "X"
//Posteriormente, alguns "X" serão substituidos por outros valores
void preenche_matriz_user(char** mat_user, int lin, int col){
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){

            if(j == col-1){
                mat_user[i][j] = '\n';
            }else{
                mat_user[i][j] = 'X';
            }
        }
    }
}



//Percorre recursivamente a matriz do campo minado, adicionando os valores a matriz do usuario
//Caso a coordenada atual na matriz do usuario nao seja um valor "X", entao retorna, pois ja foi percorrido.
//Se nao, vai para cada uma das coordenadas adjacentes, apos testar se estao dentro da matriz e sao espacos vazios.
void percorre_matriz(char** mat_campo, char** mat_user, int x, int y, int lin, int col){

    //Caso base: se ja foi percorrido, retorna
    if(mat_user[x][y] != 'X') return; 

    //Copiar o valor do campo para a matriz do usuario
    mat_user[x][y] = mat_campo[x][y];

    //Caso o valor no campo ainda seja um lugar vazio, percorre os 8 adjacentes
    if(mat_campo[x][y] == '.'){

        //Testa para cima
        if (cord_valida(x-1, y, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x-1, y, lin, col);
        }
        //Testa para baixo
        if (cord_valida(x+1, y, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x+1, y, lin, col);
        }
        //Testa para a direita
        if (cord_valida(x, y+1, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x, y+1, lin, col);
        }
        //Testa para a esquerda
        if (cord_valida(x, y-1, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x, y-1, lin, col);
        }
        //Testa para cima-direita
        if (cord_valida(x-1, y+1, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x-1, y+1, lin, col);
        }
        //Testa para cima-esquerda
        if (cord_valida(x-1, y-1, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x-1, y-1, lin, col);
        }
        //Testa para baixo-direita
        if (cord_valida(x+1, y+1, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x+1, y+1, lin, col);
        }
        //Testa para baixo-esquerda
        if (cord_valida(x+1, y-1, lin, col) == 1){
            percorre_matriz(mat_campo, mat_user, x+1, y-1, lin, col);
        }
    } 
 

}

//Lida com a interacao do usuario com o modo de jogo 3
//e printa o resultado de acordo com as coordenadas selecionadas
void interacao_usuario(char** mat_campo, char** mat_user, int x, int y, int lin, int col){

    //Caso o usuario selecione uma bomba, todo o campo é printado, mostrando que o jogo foi perdido.
    if(mat_campo[x][y] == '*'){
        printa_matriz(mat_campo, lin, col);
        return;
    }

    //Caso o usuario selecione uma dica, a matriz preenchida por "X" é printada,
    //exceto pela posicao da dica, mostrando a quantidade de bombas adjacentes
    if((mat_campo[x][y] != '.') && (mat_campo[x][y] != '*')){
        mat_user[x][y] = mat_campo[x][y]; //Adiciona a dica a matriz de "X"
        printa_matriz(mat_user, lin, col);
        return;
    }

    //Caso um espaco vazio seja selecionado, a matriz é percorrida recursivamente
    //para mostrar a vizinhanca da area vazia selecionada.
    if(mat_campo[x][y] == '.'){
        percorre_matriz(mat_campo, mat_user, x, y, lin, col);
        printa_matriz(mat_user, lin, col);
    }
}



int main(void){

	//Declaraçao de variáveis.
    short int modo;             //modo de jogo (1-3)
    FILE* arquivo = NULL;       //arquivo a ser lido

    int lin = 0, col = 0;       //linhas e colunas da matriz
    char** mat_campo = NULL;    //matriz que recebe o campo
    char** mat_user = NULL;     //matriz que será mostrada após interação
    int x, y;                   //coordenadas inseridas pelo usuario


	//Leitura do modo do jogo.
    scanf("%hd", &modo);

    //Abre o arquivo e trata de um possível erro
    arquivo = abre_arquivo(arquivo);
    
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo.");
        return -1;
    }

    //Descobrir o número de linhas e colunas
    descobre_lin_col(arquivo, &lin, &col);

    //Alocação e leitura da matriz do campo minado
    mat_campo = aloca_matriz(lin, col);
    le_matriz_campo(arquivo, mat_campo, lin, col);

    //Escolha do de jogo (1-3) a partir da variavel "modo"
    switch(modo){

    	case 1:

            //Exibir o campo inalterado
    		printa_matriz(mat_campo, lin, col);

    	break;

    	case 2:

            //Criar dicas.
            preenche_matriz_dicas(mat_campo, lin, col);

            //Exibir campo com as dicas
            printa_matriz(mat_campo, lin, col);

    	break;

    	case 3:

            //Recebe as coordenadas a partir do usuario
            scanf("%d %d", &x, &y);

            //Aloca a matriz que seja exibida ao usuario
            //E a preenche com "X"
            mat_user = aloca_matriz(lin, col);
            preenche_matriz_user(mat_user, lin, col);

            //Cria dicas no campo
            preenche_matriz_dicas(mat_campo, lin, col);

            //Percorrer a matriz a partir das coordenadas
            interacao_usuario(mat_campo, mat_user, x, y, lin, col);

    	break;
    }

    fclose(arquivo);
    free(mat_user);
    free(mat_campo);

	return 0;
}
