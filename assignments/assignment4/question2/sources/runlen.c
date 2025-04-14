#include <stdio.h>

int count(char c)
{
    if (c < '0' || c > '9')
    {
        return -1;
    }
    return c - '0';
}

int main(void)
{
    char line[128] = {0};
    scanf("%s", line);

    for (int i = 0; line[i] != '\0'; i += 2)
    {
        for (int j = 0; j < count(line[i + 1]) + 1; j++)
        {
            putchar(line[i]);
        }
    }
    putchar('\n');
    return 0;
}
