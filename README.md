# 💎 Minesweeper *in Pure C*

**Terminal implementation of the classic puzzle game with authentic gameplay mechanics**  
[![C](https://img.shields.io/badge/C-ISO_C-blue?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green)](LICENSE)

*Faithful recreation of the 1989 Robert Donner original*

---

## 🎯 Gameplay Overview

### Core Objective
Clear the minefield without detonating any bombs by:
1. Revealing safe squares
2. Using number hints (adjacent mine counts)
3. Avoiding all hidden mines

### Key Features
- **Three Game Modes**  
  1. Board Viewer  
  2. Hint-Assisted Preview  
  3. Interactive Play
- **File-Based Boards** - Load minefields from `boards` directory
- **Terminal Interface** - Keyboard-driven gameplay

---

## 🛠️ Installation & Usage

### Compilation
```bash
git clone https://github.com/voidashi/minesweeper-c.git
cd minesweeper-c
gcc -o minesweeper minesweeper.c
```

### Execution
```bash
# Start game interface
./minesweeper

# Available modes:
# 1) Print raw board
# 2) Print hinted board
# 3) Interactive play
```

### Game Flow
1. Select mode (1-3)
2. Choose board file from `boards/`
3. For interactive mode:
   - Input coordinates (row,col)
   - Reveal cells until win/loss

---

## ⚙️ Technical Implementation
- **Pure C** - No external dependencies
- **File I/O** - Load custom minefield layouts
- **Terminal Control** - Basic text interface

---

## 🤝 Contribution Guidelines
- **Bug Reports**: Through GitHub Issues
- **Enhancements**: Via Pull Requests
- **Board Designs**: Submit new `.board` files

---

## 📜 License
MIT Licensed - Full terms in [LICENSE](LICENSE)
