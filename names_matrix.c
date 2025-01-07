#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define MAXNAME 50

int isvowel(char first)
{
    if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u' || first == 'A' || first == 'E' || first == 'I' || first == 'O' || first == 'U')
        return 1;
    return 0;
}

int string_length(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void string_copy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main()
{
    int rows = 0;
    int cols = 0;

    printf("\nEnter the number of rows(1-10):");
    scanf("%d", &rows);
    while (rows < 1 || rows > 10)
    {
        printf("\nEnter the number between 1-10 only:");
        scanf("%d", &rows);
    }
    printf("\nEnter the number of columns(1-10):");
    scanf("%d", &cols);
    while (cols < 1 || cols > 10)
    {
        printf("\nEnter the number between 1-10 only:");
        scanf("%d", &cols);
    }

    char names[ROW][COL][MAXNAME];
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
            names[i][j][MAXNAME - 1] = '\0';
        }
    }
    char longest[MAXNAME] = "";
    int vowels = 0;
    printf("The 2D array of names is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%s ", names[i][j]);
            char first = names[i][j][0];
            if (isvowel(first))
                vowels++;
            if (string_length(names[i][j]) > string_length(longest))
            {
                string_copy(longest, names[i][j]);
            }
        }
        printf("\n");
    }
    printf("Number of names starting with a vowel:%d\n", vowels);
    printf("The longest name:%s\n", longest);
}