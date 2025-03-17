#include <iostream>
#include <vector>

int main(void)
{
    int num;
    std::vector<int> digits;
    std::cin >> num;
    while (num > 0)
    {
        digits.push_back(num % 10);
        num /= 10;
    }
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        std::cout << digits.at(i) << (i == 0 ? '\n' : ',');
    }

    return 0;
}