#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char Board[3][3];
char PLAYER = 'X';
char COMPUTER = 'O';

void ResetGame();
void DisplayBoard();
int CheckFreeSpaces();
void PlayersTurn();
void ComputerTurn();
char CheckWinner();
void Result(char);

//for Computer to Increse Difficulty of Gmae 
int CheckWinningMove(char);
int FindBestMove();

int main() {
    char winner = ' ';
    char playAgain;

    printf("\n****************************************\n");
    printf("*    Welocme To The Tic Tac Toe Game   *\n");
    printf("*  ---------------------------------   *\n");
    printf("*          Anuj Shrivastav             *\n");
    printf("*                                      *\n");
    printf("****************************************\n\n");

    printf("COMPUTER --> 'O'\nPLAYER --> 'X'\n ");
    
    srand(time(0)); // Set the seed for random number generation


    do {
        winner = ' ';
        ResetGame();

        while (winner == ' ' && CheckFreeSpaces() != 0) {
            DisplayBoard();

            PlayersTurn();
            winner = CheckWinner();
            if (winner != ' ' || CheckFreeSpaces() == 0) {
                break;
            }

            ComputerTurn();  
            winner = CheckWinner();
            if (winner != ' ' || CheckFreeSpaces() == 0) {
                break;
            }
        }

        DisplayBoard();
        Result(winner);

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);
    } while (playAgain == 'Y');

    printf("Thank you for playing! Goodbye.\n");

    return 0;
}

void ResetGame() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Board[i][j] = ' ';
        }   
    }
}

void DisplayBoard() {
    printf("\n");
    printf("        %c | %c | %c\n", Board[0][0], Board[0][1], Board[0][2]);
    printf("      ----|---|----\n");
    printf("        %c | %c | %c\n", Board[1][0], Board[1][1], Board[1][2]);
    printf("      ----|---|----\n");
    printf("        %c | %c | %c\n", Board[2][0], Board[2][1], Board[2][2]);
    printf("\n");
}

int CheckFreeSpaces() {
    int FreeSpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] != ' ') {
                FreeSpaces--;
            }
        }   
    }
    return FreeSpaces;
}

void PlayersTurn() {
    int x, y;

    do {
        printf("\nEnter Row #(1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter Column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid input! Please enter numbers between 1 and 3.\n");
        } else if (Board[x][y] != ' ') {
            printf("Invalid Move! Cell already taken. Try again...\n");
        } else {
            Board[x][y] = PLAYER;
            break;
        }
    } while (1);
}

void ComputerTurn() {
    int move = FindBestMove();
    int x = move / 3;
    int y = move % 3;

    if (CheckFreeSpaces() > 0) {
        Board[x][y] = COMPUTER;
    }
}

int CheckWinningMove(char symbol) {
    // Check for a winning move for the given symbol
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] == ' ') {
                Board[i][j] = symbol;
                if (CheckWinner() == symbol) {
                    Board[i][j] = ' '; // Undo move
                    return i * 3 + j;
                }
                Board[i][j] = ' '; // Undo move
            }
        }
    }
    return -1;
}

int FindBestMove() {
    // Check if computer can win in the next move
    int move = CheckWinningMove(COMPUTER);
    if (move != -1) {
        return move;
    }

    // Check if player could win on their next move, and block them
    move = CheckWinningMove(PLAYER);
    if (move != -1) {
        return move;
    }

    // Otherwise, choose a random move (could be improved further)
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (Board[x][y] != ' ');

    return x * 3 + y;
}

char CheckWinner() {

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] && Board[i][0] != ' ') {
            return Board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i] && Board[0][i] != ' ') {
            return Board[0][i];
        }
    }

    // Check diagonals
    if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] && Board[0][0] != ' ') {
        return Board[0][0];
    }
    if (Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0] && Board[0][2] != ' ') {
        return Board[0][2];
    }

    return ' ';
}

void Result(char winner) {
    if (winner == PLAYER) {
        printf("You Win! Congratulations!\n");   
    } else if (winner == COMPUTER) {
        printf("You Lose! Better luck next time.\n");   
    } else {
        printf("It's a Draw! Well played.\n");  
    }
}
