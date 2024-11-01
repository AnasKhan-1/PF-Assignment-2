#include <stdio.h>

void HorizontalHistogram(int values[], int count) 
{
	int i, j;
    printf("\t\tHorizontal Histogram:\n\n");
    for ( i = 0; i < count; i++) 
	{
        printf("Value %d: ", i + 1);
        for ( j = 0; j < values[i]; j++) 
		{
            printf("*");
        }
        printf("\n");
    }
}

void VerticalHistogram(int values[], int count) 
{
	int i, j;
    int Height = 0;
    for (i = 1; i < count; i++) 
	{
        if (values[i] > Height) 
		{
            Height = values[i];
        }
    }

    printf("\t\tVertical Histogram:\n\n");
    for ( i = Height; i > 0; i--) 
	{
        for ( j = 0; j < count; j++) 
		{
            if (values[j] >= i) 
			{
                printf("* ");
            }
			else 
			{
                printf("  ");
            }
        }
        printf("\n");
    }

    for ( i = 0; i < count; i++) 
	{
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() 
{
    int values[] = {4, 5, 8, 2};
    int count = sizeof(values) / sizeof(values[0]);

    HorizontalHistogram(values, count);
    VerticalHistogram(values, count);

    return 0;
}

