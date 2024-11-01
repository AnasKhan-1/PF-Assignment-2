#include <stdio.h>
int WinMove(int N) 
{
    if (N % 5 == 0) 
	{
    	return -1;
    } 
	else 
	{
        return N % 5;
    }
}
int main() 
{
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    int result = WinMove(N);

    if (result == -1) 
	{
        printf("Impossible for A to win the game");
    } 
	else 
	{
        printf("A should pick %d matchsticks on first turn to secure the win", result);
    }

    return 0;
}
