#include <iostream>

int pow(int base, int exp);

int main(void)
{
    int num;
    std::cin >> num;

    for (int i = 4; i >= 0; i--)
    {
        std::cout << (num / pow(10, i) % 10) << (i == 0 ? '\n' : ',');
    }
}

int pow(int base, int exp)
{
    if (exp < 0)
    {
        return 0;
    }
    if (exp == 0)
    {
        return 1;
    }
    if (exp == 1)
    {
        return base;
    }
    return pow(base, exp / 2) * pow(base, exp - exp / 2);
}