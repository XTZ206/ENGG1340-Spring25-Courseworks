#include <iostream>

int main(void)
{
    double a[2][2] = {{2, 3}, {3, 2}};
    std::cout << a[0][0] << std::endl;
    std::cout << a[0][1] << std::endl;
    std::cout << a[1][0] << std::endl;
    std::cout << a[1][1] << std::endl;

    double b[1][2] = {{3}};
    std::cout << b[0][0] << std::endl;
    std::cout << b[0][1] << std::endl;

    char string[1000] = "string";
    std::cout << &string[0] << std::endl;
    return 0;
}