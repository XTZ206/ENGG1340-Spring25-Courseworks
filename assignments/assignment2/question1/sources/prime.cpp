#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void update_prime(int n);
bool is_prime(int n);
std::vector<char> primes = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1};

int main(void)
{

    std::cout << "Primes: ";
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes.at(i) == 1)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

bool is_prime(int n)
{
    if (n < primes.size())
    {
        return (bool)primes.at(n);
    }
    if (n / 2 < primes.size())
    {
        update_primes(primes.size() / 2 * 3);
    }

    return (bool)primes.at(n);
}

void update_primes(int n)
{
    if (n < primes.size())
        return;
    if (n / 2 > primes.size())
        update_primes(n / 2);
    for (int i = primes.size(); i < n; i++)
    {
        for (auto prime : primes)
        {
            if (i % prime == 0)
            {
                primes.push_back(0);
                break;
            }
        }
    }
}
