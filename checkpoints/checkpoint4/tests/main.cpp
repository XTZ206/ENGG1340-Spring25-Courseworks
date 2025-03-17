#include <iostream>
#include "mathint.hpp"

int main(void)
{
    int x, y;
    std::cout << "Please enter two integers: ";
    std::cin >> x >> y;
    std::cout << "GCD: " << gcd(x, y) << std::endl;
    std::cout << "LCM: " << lcm(x, y) << std::endl;
    return 0;
}