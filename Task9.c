#include <stdio.h>

const int SIZE = 5; // Declare a constant variable for grid size

void displayGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerRow = 4, playerCol = 4; // Starting position of 'P'
    char move;

    while (1) {
        displayGrid(grid);
        printf("Enter your move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        int newRow = playerRow, newCol = playerCol;

        switch (move) {
            case 'W': case 'w':
                newRow--;
                break;
            case 'S': case 's':
                newRow++;
                break;
            case 'A': case 'a':
                newCol--;
                break;
            case 'D': case 'd':
                newCol++;
                break;
            case 'Q': case 'q':
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid move! Please try again.\n");
                continue;
        }

        // Check for valid moves
        if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE) {
            if (grid[newRow][newCol] != 'X') {
                // Update grid and player's position
                grid[playerRow][playerCol] = ' '; // Clear the previous position
                playerRow = newRow;
                playerCol = newCol;

                // Collect item if present
                if (grid[playerRow][playerCol] == 'I') {
                    printf("You collected an item!\n");
                    grid[playerRow][playerCol] = ' '; // Remove the item from the grid
                }
                grid[playerRow][playerCol] = 'P'; // Update player's position
            } else {
                printf("You cannot move into an obstacle!\n");
            }
        } else {
            printf("Invalid move! Out of bounds!\n");
        }
    }

    return 0;
}

