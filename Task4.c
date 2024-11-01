#include <stdio.h>
#include <string.h>

int main() {
    char Transactions[][20] = {"eat", "tea", "tan", "ate", "nat", "bat"}, SortedArray[20], temp;
    int NumOfTransactions = sizeof(Transactions) / sizeof(Transactions[0]);
    char Groups[100][100][20];
    int GroupSizes[100] = {0}, GroupCount = 0, i, j, x, y;


    for ( i = 0; i < NumOfTransactions; i++) 
	{
        strcpy(SortedArray, Transactions[i]);
        int Length = strlen(SortedArray);
        
        for ( x = 0; x < Length - 1; x++) 
		{
            for ( y = 0; y < Length - x - 1; y++) 
			{
                if (SortedArray[y] > SortedArray[y + 1]) 
				{
                    temp = SortedArray[y];
                    SortedArray[y] = SortedArray[y + 1];
                    SortedArray[y + 1] = temp;
                }
            }
        }
        int Flag = 0;
        for ( j = 0; j < GroupCount; j++) 
		{
            if (strcmp(Groups[j][0], SortedArray) == 0) 
			{
                strcpy(Groups[j][GroupSizes[j]], Transactions[i]);
                GroupSizes[j]++;
                Flag = 1;
                break;
            }
        }

        if (Flag==0) 
		{
            strcpy(Groups[GroupCount][0], SortedArray);
            strcpy(Groups[GroupCount][1], Transactions[i]);
            GroupSizes[GroupCount] = 2;
            GroupCount++;
        }
    }
    printf("Grouped Transactions: ");
    for ( i = 0; i < GroupCount; i++) 
	{
        printf("[");
        for ( j = 1; j < GroupSizes[i]; j++) 
		{
            printf("%s", Groups[i][j]);
            if (j < GroupSizes[i] - 1) printf(", ");
        }
        printf("], ");
    }
    return 0;
}

