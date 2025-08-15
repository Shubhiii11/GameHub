# 🎮 Game Hub

**Game Hub** is a console-based C++ mini arcade featuring **three classic games**:  
- **Tic Tac Toe** (3×3 and 4×4 modes, with Player vs Player or Player vs Computer)  
- **Memory Match** (flip and match emoji pairs)  
- **8-Puzzle** (sliding number puzzle)  

Enjoy a colorful, text-based gaming experience directly in your terminal.

---

## 📜 Features

### 🟢 Tic Tac Toe
- **Board Sizes:** Play in 3×3 or 4×4 grid.
- **Game Modes:** 
  - Player vs Player  
  - Player vs Computer (with basic AI for blocking and winning moves)
- **Winning Conditions:** Align X's or O's horizontally, vertically, or diagonally.
- **Exit Anytime:** Enter `0` to quit mid-game.
- **Color-coded output** for better readability.

---

### 🟡 Memory Match
- **Grid Size:** 4×4 board with 8 pairs of symbols.
- **Gameplay:**  
  - Flip two cards at a time.
  - If they match, they remain revealed.
  - If not, they are hidden again.
- **Win Condition:** Match all pairs.
- **Exit Anytime:** Enter `0` to quit mid-game.
- **Shuffling:** Randomized card placement each round.

---

### 🔵 8-Puzzle
- **Objective:** Arrange numbers `1` to `8` in order with an empty space at the end.
- **Controls:**  
  - `U` = Move Up  
  - `D` = Move Down  
  - `L` = Move Left  
  - `R` = Move Right  
  - `Q` = Quit
- **Light Shuffle:** Ensures the puzzle starts solvable.
- **Win Condition:** Match the solved state.

---

## 🖥️ How to Run

### Prerequisites
- A C++ compiler (e.g., `g++`)
- A terminal or command prompt that supports ANSI color codes.

### Compile & Run
```bash
g++ "final code.cpp" -o gamehub
./gamehub
```

---

## 📂 File Structure
```
.
├── final code.cpp   # Main game hub source code
└── README.md        # Project description and instructions
```

---

## 🕹️ Main Menu
When you run the program, you’ll see:
```
==== Game Hub ====
1. Tic Tac Toe
2. Memory Match
3. 8-Puzzle
4. Exit
Choose:
```
Enter a number to start your chosen game.

---

## 📌 Notes
- Works best on Windows command prompt for `system("cls")` and `_getch()` to function correctly.
- The code uses ANSI escape sequences for color; some terminals may need configuration to display them properly.

---

## 📜 License
This project is open-source under the MIT License — feel free to use, modify, and share.
