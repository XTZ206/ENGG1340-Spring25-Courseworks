#include <iostream>

int main(void)
{
    int num;
    std::cin >> num;
    std::cout << num / 10000 << ','
              << num / 1000 % 10 << ','
              << num / 100 % 10 << ','
              << num / 10 % 10 << ','
              << num % 10 << '\n';
    return 0;
}