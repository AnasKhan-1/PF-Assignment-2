#include <stdio.h>
#include <string.h>

int main() {
    int Length, LengthString, j, NewIndex, i;
    char CurrentWord[50];
    char WordArray[3][50] = {"booooook", "coooool", "heeeey"};
    char FixWord[50];

    Length = sizeof(WordArray) / sizeof(WordArray[0]);

    for (i = 0; i < Length; i++) {
        int k = 0;
        while (WordArray[i][k] != '\0') {
            CurrentWord[k] = WordArray[i][k];
            k++;
        }
        CurrentWord[k] = '\0';

        LengthString = k;
        NewIndex = 0;
        
        for (j = 0; j < LengthString; j++) {
            FixWord[NewIndex++] = CurrentWord[j];
            
            while (j < LengthString - 1 && CurrentWord[j] == CurrentWord[j + 1]) {
                j++;
            }
        }
        
        FixWord[NewIndex] = '\0';
        printf("Original Word: %s		Fixed Word: %s\n", CurrentWord, FixWord);
    }

    return 0;
}

