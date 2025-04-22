#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *data;
    int length;
    int capacity;
};

void print(struct Stack *stack)
{
    printf("[%d]", stack->capacity);
    for (int i = 0; i < stack->length; i++)
    {
        printf(" %d", stack->data[i]);
    }
    printf("\n");
}

int main(void)
{
    struct Stack stack = {malloc(sizeof(int)), 0, 1};

    for (char c = getchar(); c != '='; c = getchar())
    {
        if (c >= '0' && c <= '9')
        {
            stack.data[stack.length++] = c - '0';
            if (stack.length == stack.capacity)
            {
                stack.capacity *= 2;
                stack.data = realloc(stack.data, sizeof(int) * stack.capacity);
            }
        }
        else if (c == '+')
        {
            int b = stack.data[--stack.length];
            int a = stack.data[--stack.length];
            stack.data[stack.length++] = a + b;
        }
        else if (c == '-')
        {
            int b = stack.data[--stack.length];
            int a = stack.data[--stack.length];
            stack.data[stack.length++] = a - b;
        }
        print(&stack);
    }

    free(stack.data);

    return 0;
}
