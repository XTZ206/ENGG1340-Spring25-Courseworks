#include <iostream>
#include <string>

int main(void)
{

    std::string buffer;
    std::getline(std::cin, buffer);
    std::string oldstr;
    std::cin >> oldstr;
    std::string newstr;
    std::cin >> newstr;

    int pos = 0;
    while ((pos = buffer.find(oldstr, pos)) != std::string::npos)
    {
        buffer.replace(pos, oldstr.length(), newstr);
        pos += newstr.length();
    }
    std::cout << buffer << std::endl;

    return 0;
}