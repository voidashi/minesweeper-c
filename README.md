# 💎 Minesweeper in C

**A terminal-based implementation of the classic Minesweeper game, built in C.**  
Navigate through a minefield without detonating any bombs while revealing safe squares!

---

## 🎮 About the Game

Minesweeper is a single-player puzzle game, originally invented by Robert Donner in 1989. The objective is to clear a rectangular field of hidden mines without triggering any of them. The game is renowned for its simplicity and strategic depth.

---

## 📜 Rules

- The game area consists of a rectangular grid of squares.
- Clicking on a square reveals its contents:
  1. If it contains a mine, the game is over.
  2. If it’s safe, it either shows a number indicating adjacent mines or reveals adjacent squares if empty.
- You win by revealing all squares that don’t contain mines.

---

## 🛠️ Usage

After executing the program, choose an option:

1. **Print the Board**  
   Reads a board name from `stdin` (examples included in the `boards` directory) and prints the unaltered board to `stdout`.

2. **Print the Board with Hints**  
   Similar to option 1 but includes hints on adjacent mines.

3. **User Action**  
   Reads a board name and user-specified coordinates to reveal squares until mines are encountered.

---

## 🚀 Getting Started

### Clone the Repository

```bash
git clone https://github.com/voidashi/minesweeper-c.git
```

### Compilation

Use a C compiler (like `gcc`) to compile the source files:

```bash
gcc -o minesweeper minesweeper.c
```

### Running the Game

Run the executable to start playing:

```bash
./minesweeper
```

---

## 🤝 Contributing

Feel free to open issues or submit pull requests to improve this project!

---

## 📄 License

This project is licensed under the [MIT License](./LICENSE).
