#include <iostream>

int pow(int base, int exp)
{
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base;
    else if (exp == 2)
        return base * base;
    else
        return pow(base, exp / 2) * pow(base, exp - exp / 2);
}

int main(void)
{
    int arr[15];
    int n;
    std::cin >> n;
    if (n >= 15)
    {
        for (int i = 0; i < 15; i++)
        {
            arr[i] = i * i;
        }
    }
    else if (n >= 10)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = i * i;
        }
        for (int i = n; i < 15; i++)
        {
            arr[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = i * i;
        }
        for (int i = n; i < n + 5; i++)
        {
            arr[i] = 0;
        }
        for (int i = n + 5; i < 15; i++)
        {
            arr[i] = pow(3, i);
        }
    }

    for (int i = 0; i < 15; i++)
    {
        std::cout << arr[i] << (i < 15 - 1 ? " " : "\n");
    }

    return 0;
}