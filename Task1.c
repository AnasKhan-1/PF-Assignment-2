#include <stdio.h>

int main() {
    int Array[5], i, j, temp;
    int Small, SecondSmall;

    for (i = 0; i < 5; i++) {
        printf("Enter Element: %d ", i + 1);
        scanf("%d", &Array[i]);
        
        if (Array[i] > 9999) {
            printf("Number can't be bigger than 9999\n");
            return 1;
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            if (Array[j] > Array[j + 1]) {
                temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }

    Small = Array[0];


    for (i = 1; i < 5; i++) {
        if (Array[i] != Small) {
            SecondSmall = Array[i];
            break;
        }
    }


    printf("The Smallest number is %d and the second smallest number is %d\n", Small, SecondSmall);

    return 0;
}

