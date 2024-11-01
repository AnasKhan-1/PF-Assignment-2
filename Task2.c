#include <stdio.h>

int main() {
    char slogans[3][50] = {"buy now", "save big", "limited offer"};
    int times[256],  i,  j, k;
    
    for (i = 0; i < 3; i++) 
	{
        for (k = 0; k < 256; k++) 
		{
            times[k] = 0;
        }
        
        for (j = 0; slogans[i][j] != '\0'; j++)
		{
            times[(int)slogans[i][j]]++;
        }

        printf("Slogan: %s\n", slogans[i]);
        for (k = 0; k < 256; k++) 
		{
            if (times[k] > 0) 
			{
                printf("%c: %d\n", k, times[k]);
            }
        }
        printf("\n");
    }

    return 0;
}

