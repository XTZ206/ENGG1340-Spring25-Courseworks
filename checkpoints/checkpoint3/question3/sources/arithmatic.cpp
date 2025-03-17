#include <iostream>

int main(void)
{
    std::cout << 6 + 3 * 7 / 1 - 2 << std::endl;
    std::cout << 3 % 3 + 3 * 2 - 2 / 2 << std::endl;

    int x = 5, y = 6, z = 7;
    std::cout << (x + z) % y << std::endl;
    std::cout << (x % y) % z << std::endl;
    std::cout << (x * z) % y << std::endl;

    return 0;
}