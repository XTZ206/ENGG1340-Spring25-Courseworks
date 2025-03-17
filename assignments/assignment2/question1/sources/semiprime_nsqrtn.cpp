#include <iostream>

bool is_prime(int n);
bool is_semiprime(int n, int *p1 = nullptr, int *p2 = nullptr);

int main(void)
{
    int s, a, b;
    std::cin >> s;
    while (!is_semiprime(s, &a, &b))
    {
        s++;
    }
    std::cout << a << " " << b << " " << s << std::endl;
    return 0;
}

bool is_prime(int n)
{
    if (n == 0 || n == 1 || n == 4)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool is_semiprime(int n, int *p1, int *p2)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    if (is_prime(n))
    {
        return false;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0 && is_prime(i) && is_prime(n / i) && i * i != n)
        {
            *p1 = i;
            *p2 = n / i;
            return true;
        }
    }
    return false;
}