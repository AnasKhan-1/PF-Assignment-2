#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generateRandom(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

int horizontalCheck(char input[], char grid[6][5], int len)  
{
	int  i, j, k;
    for ( i = 0; i < 6; i++) 
	{
        for ( j = 0; j <= 5 - len; j++) 
		{
            for (k = 0; k < len; k++) 
			{
                if (grid[i][j + k] != input[k]) 
				{
                    break;
                }
            }
            if (k == len) 
			{
                return 1;
            }
        }
    }
    return 0;
}

int verticalCheck(char input[], char grid[6][5], int len) 
{
	int  i, j, k;
    for ( j = 0; j < 5; j++) 
	{
        for ( i = 0; i <= 6 - len; i++) 
		{
            for (k = 0; k < len; k++) 
			{
                if (grid[i + k][j] != input[k]) 
				{
                    break;
                }
            }
            if (k == len) 
			{
                return 1;
            }
        }
    }
    return 0;
}

int diagonalCheck(char input[], char grid[6][5], int len) 
{
	int  i, j, k;
    for ( i = 0; i <= 6 - len; i++)
	{
        for ( j = 0; j <= 5 - len; j++) 
		{
            for (k = 0; k < len; k++) 
			{
                if (grid[i + k][j + k] != input[k]) 
				{
                    break;
                }
            }
            if (k == len) 
			{
                return 1;
            }
        }
    }

    for ( i = 0; i <= 6 - len; i++) 
	{
        for ( j = len - 1; j < 5; j++) 
		{
            for (k = 0; k < len; k++) 
			{
                if (grid[i + k][j - k] != input[k]) 
				{
                    break;
                }
            }
            if (k == len) 
			{
                return 1;
            }
        }
    }

    return 0;
}

int main() 
{
	int  i, j, k;
    srand(time(0));

    char grid[6][5];
    int score = 0;

    for ( i = 0; i < 6; i++) 
	{
        for ( j = 0; j < 5; j++) 
		{
            grid[i][j] = generateRandom(97, 122);
        }
    }

    grid[5][0] = '2';
    grid[5][1] = '5';
    grid[5][2] = '3';
    grid[5][3] = '4';

    for ( i = 0; i < 6; i++) 
	{
        for ( j = 0; j < 5; j++) 
		{
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    while (1) 
	{
        char input[30];
        printf("Enter a string: ");
        scanf("%s", input);

        int len = strlen(input);
        int found = horizontalCheck(input, grid, len) ||
                    verticalCheck(input, grid, len) ||
                    diagonalCheck(input, grid, len);

        if (found) 
		{
            score++;
            printf("%s is present. Score: %d\n", input, score);
        } else {
            score--;
            if (score < 0) 
			{
                score = 0;
            }
            printf("%s is not present. Score: %d\n", input, score);
        }
    }

    return 0;
}
