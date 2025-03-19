#include <stdio.h>
#include <string.h>

void to_lower(char str[])
{
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str + ('a' - 'A');
        }
        str++;
    }
    
}

int main(void)
{
    char input[100];
    scanf("%s", input);
    to_lower(input);
    printf("%s", input);
    return 0;
}