#include <stdio.h>
#define MAX_BUFFER_SIZE 100

int main()
{
    char c;
    int i;
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter a character:\n ");
    for (i = 0; i < (c = getchar()) != EOF && i < MAX_BUFFER_SIZE - 1; i++)

    {
        buffer[i] = c;
    }
    buffer[i] = '\0';

    printf("You entered: %s\n", buffer);
    return 0;
}