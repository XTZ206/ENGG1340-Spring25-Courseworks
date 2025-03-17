#include <iostream>

int main(void)
{
    double sum = 0;
    int count = 0;

    while (true)
    {
        double item;
        std::cin >> item;
        if (item == -1)
        {
            break;
        }
        sum += item;
        count++;
    }
    std::cout << sum / count << std::endl;

    return 0;
}