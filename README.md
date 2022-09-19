# minesweeper-c

## O jogo
Campo Minado é um popular jogo de computador para um jogador. Foi inventado por
Robert Donner em 1989 e tem como objetivo revelar um campo de minas sem que alguma
seja detonada. Este jogo tem sido reescrito para as mais diversas plataformas, sendo a
sua versão mais popular a incluída nativamente com o Microsoft Windows.

## Regras

A área de jogo consiste num campo de quadrados retangular. Cada quadrado pode ser
revelado clicando sobre ele, e se o quadrado clicado contiver uma mina, então o jogo
acaba. Se, por outro lado, o quadrado não contiver uma mina, uma de duas coisas
poderá acontecer:
1. Um número aparece, indicando a quantidade de quadrados adjacentes que contêm
minas;
2. Nenhum número aparece. Neste caso, o jogo revela automaticamente os quadrados
que se encontram adjacentes ao quadrado vazio, já que não podem conter minas;
O jogo é ganho quando todos os quadrados que não têm minas são revelados.

## Uso do programa
Após a execução do programa, deve ser inserida a opção desejada.

### Opção 1: Imprimir o tabuleiro
lê o nome de um tabuleiro do stdin (exemplos inclusos na pasta boards) e imprime o tabuleiro inalterado para o stdout

### Opção 2: mprimir o tabuleiro com as dicas
lê o nome de um tabuleiro do stdin (exemplos inclusos na pasta boards) e imprime o tabuleiro com dias para o stdout

### Opção 3: ação do usuário
lê o nome de um tabuleiro do stdin (exemplos inclusos na pasta boards), e, após isso, as coordenadas em que o usuário deseja clicar, revelando o tabuleiro exposto até que sejam encontradas bordas de minas.

