# Tic Tac Toe Game (C Language)

A command-line implementation of the classic Tic Tac Toe game in C with an enhanced console interface and modular function structure.

## Features

- **Clean Console Display**: ASCII-based board with clear formatting
- **Modular Design**: Separate functions for each game task
- **Input Validation**: Checks for valid positions and occupied cells
- **Game Logic**: 
  - First 3 moves: Players place their pieces on empty squares
  - Subsequent moves: Players remove an old piece and place a new one
- **Win Detection**: Checks for winners in rows, columns, and diagonals
- **Player Feedback**: Error messages with visual indicators for invalid inputs

## Game Rules

1. **Players**: O vs X (alternating turns)
2. **Objective**: Get 3 of your symbols in a row (horizontally, vertically, or diagonally)
3. **Phase 1 (Moves 1-3)**: Each player places one piece per turn on an empty square
4. **Phase 2 (Moves 4+)**: Each player must remove an existing piece before placing a new one
5. **Win Condition**: First player to get 3 in a line wins

## Position Format

Positions are entered as (row column) using 0-2 indexing. The board displays row numbers on the right side for easy reference:

```
  0   1   2  (columns)
+-----+-----+-----+  0 (rows)
|     |     |     |  0
+-----+-----+-----+
|     |     |     |  1
+-----+-----+-----+
|     |     |     |  2
+-----+-----+-----+
```

Example: Enter `0 1` to place in row 0, column 1

## Running the Game

**Option 1: Direct Play (Windows Users)**
- A compiled executable `TicTacToe_C.exe` is included in the repository
- Simply double-click `TicTacToe_C.exe` to play immediately without compilation

**Option 2: From Terminal**
```bash
./TicTacToe_C
```

Or on Windows:
```bash
TicTacToe_C.exe
```

**Option 3: Compile from Source**
If you want to recompile on your system:
```bash
gcc -std=c11 -o TicTacToe_C TicTacToe_C.c
./TicTacToe_C
```

## How to Play

1. Run the executable
2. Read the instructions displayed at start
3. Players take turns entering positions
4. For moves 1-3: Enter the position where you want to place your piece
5. For moves 4+: 
   - First, enter the position of the piece you want to remove
   - Then, enter the position where you want to place the new piece
6. Game ends when one player wins

## Code Structure

### Functions

| Function | Purpose |
|----------|---------|
| `displayBoard()` | Displays the current game board |
| `displayInstructions()` | Shows game rules and instructions |
| `checkColumns()` | Checks if a player won by column |
| `checkRows()` | Checks if a player won by row |
| `checkDiagonals()` | Checks if a player won by diagonal |
| `checkWinner()` | Unified winner check function |
| `announceWinner()` | Displays winner message and exits |
| `getOInputInitial()` | Handles O's first 3 moves |
| `getXInputInitial()` | Handles X's first 3 moves |
| `getOMoveAfter3()` | Handles O's moves after initial 3 pieces |
| `getXMoveAfter3()` | Handles X's moves after initial 3 pieces |

## Example Game Session

```
    +========================================+
    |      TIC TAC TOE - Game Instructions   |
    +========================================+
    |  1. Enter positions in matrix format   |
    |     (row column) starting from 0-2     |
    |                                        |
    |  2. First 3 moves: Place pieces       |
    |     After that: Remove old, add new   |
    |                                        |
    |  3. Win: Get 3 in a row/column/       |
    |     diagonal                          |
    +========================================+

    +-----+-----+-----+  
    |  O  |     |     |  0
    +-----+-----+-----+
    |     |  X  |     |  1
    +-----+-----+-----+
    |     |     |     |  2
    +-----+-----+-----+
      0     1     2

    [X] Enter position (row column): 2 2
    ...
```

Note: The board now displays row numbers on the right side for easier reference.

## Error Messages

- `Invalid position! Use 0-2 for row and column.` - Position out of bounds
- `Position already occupied! Try again.` - Square is already taken
- `Invalid position to remove! Try again.` - Piece doesn't exist at that location

## Requirements

- C compiler (gcc, clang, or MSVC)
- Standard C library support (C11 standard)

## Author Notes

This implementation demonstrates:
- Modular function design
- Input validation and error handling
- Game state management
- Algorithm for win detection
- Enhanced user interface with ASCII formatting

Enjoy the game!
