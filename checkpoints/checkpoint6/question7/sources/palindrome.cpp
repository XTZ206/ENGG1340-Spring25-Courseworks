#include <iostream>
#include <string>
#include <cstring>

bool is_palindrome(const char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    std::string buffer;
    std::getline(std::cin, buffer);
    // Remove all non-alphabetic characters
    for (int i = 0; i < buffer.length(); i++)
    {
        char c = buffer[i];
        if (!isalpha(c))
        {
            buffer.erase(i, 1);
            i--;
        }
    }
    // Convert all characters to lowercase
    for (int i = 0; i < buffer.length(); i++)
    {
        if (buffer[i] >= 'A' && buffer[i] <= 'Z')
        {
            buffer[i] = buffer[i] - 'A' + 'a';
        }
    }

    if (is_palindrome(buffer.c_str()))
    {
        std::cout << "The input string is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The input string is not a palindrome." << std::endl;
    }
}