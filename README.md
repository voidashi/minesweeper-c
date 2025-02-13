# 💎 Minesweeper in C  

*A terminal-based implementation of the classic Minesweeper game, built in C.*  

[![C](https://img.shields.io/badge/Language-C-informational?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))  
[![License](https://img.shields.io/badge/License-MIT-green?style=flat)](LICENSE)  

---

## 📦 Features  

### **Core Gameplay**  
- Classic Minesweeper mechanics: Reveal safe squares, avoid mines, and win by clearing the board.  
- **Rules:**  
  - Grid of squares hides mines or safe zones.  
  - Reveal a mine: Game over.  
  - Reveal safe squares: Displays adjacent mine count or auto-reveals empty areas.  

### **Key Functionality**  
- **Multiple Modes:**  
  1. **Print Board:** Display unaltered board from `boards/` directory.  
  2. **Hints Mode:** Show boards with adjacent mine counts.  
  3. **Interactive Play:** Input coordinates to reveal squares dynamically.  
- **Terminal-First Design:** Lightweight and runs natively in any UNIX-like environment.  

---

## 🚀 Getting Started  

### **Clone the Repository**  
```bash  
git clone https://github.com/voidashi/minesweeper-c.git  
```  

### **Compilation**  
Compile with `gcc`:  
```bash  
gcc -o minesweeper minesweeper.c  
```  

### **Run the Game**  
Start the executable:  
```bash  
./minesweeper  
```  

**Note:** Ensure board files are in the `boards/` directory!  

---

## 🕹️ Usage  
After launching the game, choose an action:  
1. **Print Board** – Load and display a predefined board.  
2. **Print Board with Hints** – Add mine-count hints to the board.  
3. **User Action** – Enter coordinates interactively to reveal squares.  

---

## 🤝 Contributing  
Found a bug or have an idea?  
- Open an **Issue** for feature requests or bug reports.  
- Submit a **Pull Request** for documented fixes or enhancements.  

---

## 📄 License  
MIT Licensed - See [LICENSE](LICENSE) for details.  

---  

*Relive the 90s magic—now in your terminal!*  
