#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int BinaryToDecimal(const char* binaryNum) 
{
    int decimalNum = 0;
    while (*binaryNum) 
    {
        decimalNum = (decimalNum << 1) + (*binaryNum - '0');
        binaryNum++;
    }
    return decimalNum;
}

void DecimalToBinary(int decimalNum) 
{
    if (decimalNum == 0) {
        printf("%d in decimal is 0 in binary\n", decimalNum);
        return;
    }

    char binaryNum[32];
    int index = 0, originalDecimal = decimalNum;

    while (decimalNum > 0) 
    {
        binaryNum[index++] = (decimalNum % 2) + '0';
        decimalNum /= 2;
    }
    
    int i;
    printf("%d in decimal is ", originalDecimal);
    for (i = index - 1; i >= 0; i--) 
    {
        printf("%c", binaryNum[i]);
    }
    printf(" in binary\n");
}

void DecimalToHexadecimal(int decimalNum) 
{
    if (decimalNum == 0) {
        printf("%d in decimal is 0 in hexadecimal\n", decimalNum);
        return;
    }

    char hexNum[100];
    int i = 0, originalDecimal = decimalNum;
    while (decimalNum != 0) 
    {
        int temp = decimalNum % 16;
        hexNum[i++] = (temp < 10) ? (temp + '0') : (temp + 55);
        decimalNum /= 16;
    }

    int j;
    printf("%d in decimal is ", originalDecimal);
    for (j = i - 1; j >= 0; j--) 
    {
        printf("%c", hexNum[j]);
    }
    printf(" in hexadecimal\n");
}

int HexadecimalToDecimal(const char* hexNum) 
{
    int decimalNum = 0;
    while (*hexNum) 
    {
        decimalNum = decimalNum * 16 + (*hexNum >= '0' && *hexNum <= '9' ? *hexNum - '0' : *hexNum - 'A' + 10);
        hexNum++;
    }
    return decimalNum;
}

void BinaryToHexadecimal(const char* binaryNum) 
{
    int decimalNum = BinaryToDecimal(binaryNum);
    printf("%s in binary is ", binaryNum);
    DecimalToHexadecimal(decimalNum);
}

void HexadecimalToBinary(const char* hexNum) 
{
    int decimalNum = HexadecimalToDecimal(hexNum);
    printf("%s in hexadecimal is ", hexNum);
    DecimalToBinary(decimalNum);
}

int main() 
{
    int choice;
    char binaryNumber[33];
    char hexNumber[100];
    int decimalNumber;

    while (1) 
    {
        printf("\tMenu:\n\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter a binary number: ");
                scanf("%s", binaryNumber);
                printf("%s in binary is %d in decimal\n", binaryNumber, BinaryToDecimal(binaryNumber));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                DecimalToBinary(decimalNumber);
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                DecimalToHexadecimal(decimalNumber);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("%s in hexadecimal is %d in decimal\n", hexNumber, HexadecimalToDecimal(hexNumber));
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%s", binaryNumber);
                printf("%s in binary is ", binaryNumber);
                BinaryToHexadecimal(binaryNumber);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("%s in hexadecimal is ", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

