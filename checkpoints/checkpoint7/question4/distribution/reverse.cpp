#include <iostream>
#include <string>

std::string reverse(const std::string s)
{
    if (s.size() == 0)
    {
        return "";
    }
    else
    {
        return reverse(s.substr(1)) + s[0];
    }
}

int main(void)
{
    std::string s;
    std::cin >> s;

    std::cout << "String in reverse = " << reverse(s) << std::endl;
    return 0;
}