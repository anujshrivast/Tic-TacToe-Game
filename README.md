# Tic-TacToe-Game CLI

Technologies Used:
C, Standard Libraries (stdio.h, stdlib.h, ctype.h, time.h)


Developed a command-line Tic Tac Toe game in C, featuring both player and computer modes. Implemented comprehensive game logic, including player turns, computer AI, and conditions for winning or drawing the game. Enhanced the game's difficulty by incorporating strategic moves and random number generation. Improved user interaction through intuitive prompts and input validation. Applied clean and modular coding practices to ensure the maintainability and readability of the code.


# Tic Tac Toe Game with computer Opponent

Welcome to the Tic Tac Toe game developed in C++. This console-based game features both player vs. player and player vs. computer modes, providing a challenging and engaging experience with a built-in AI opponent.

## Features

- **Game Mechanics**: 
  - Functions to reset the game board, display the current state of the board, check for available moves, handle player turns, and determine the winner.
  
- **AI Opponent**:
  - A computer opponent that uses a strategic algorithm to make winning moves or block the player’s potential winning moves, increasing the difficulty of the game.
  
- **User Input Validation**:
  - Player names are validated to ensure they consist only of alphabetic characters and spaces using regular expressions.
  - Player moves are validated to ensure they are within the valid range and that chosen cells are not already occupied.

- **Winner Determination**:
  - The game checks for a winner after each move by evaluating rows, columns, and diagonals for three matching symbols and declares the winner accordingly or notes if the game ends in a draw.
  
- **Replay Option**:
  - After each game, players are given the option to play again, allowing for continuous gameplay.

## How to Play

1. **Start the Game**: Run the executable file to start the game.
2. **Registration**: Enter your name, roll number, and email address for validation and registration.
3. **Play the Game**: Choose to play against another player or the computer.
   - Enter your moves by specifying the row and column number.
   - The computer will make its move in the player vs. computer mode.
4. **Determine the Winner**: The game will check for a winner or a draw after each move.
5. **Replay**: After the game ends, choose to play again or exit.

