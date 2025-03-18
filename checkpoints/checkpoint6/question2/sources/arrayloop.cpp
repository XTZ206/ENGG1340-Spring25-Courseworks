#include <iostream>

void func(int a[], int b[], int c[], int d)
{
    for (int index = d - 1; index >= 0; index--)
    {
        a[index] = 2;
        b[index] = 3;
        c[index] = 4;
    }
    for (int i = 0; i < d; i++)
    {
        std::cout << a[i] << " ";
        std::cout << b[i] << " ";
        std::cout << c[i] << " ";
    }
}

int main(void)
{
    int a[] = {1, 2, 3};
    int b[] = {3, 4, 5};
    int c[] = {5, 6, 7};

    func(a, b, c, 3);
    func(a, b, c, 5);

    return 0;
}