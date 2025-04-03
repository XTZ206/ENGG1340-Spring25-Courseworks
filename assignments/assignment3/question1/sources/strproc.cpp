#include <iostream>
#include <string>

int main(void)
{
    std::string input;
    std::string output;
    std::string word;
    std::string longest;

    input.reserve(100);
    output.reserve(100);

    std::getline(std::cin, input);
    for (auto i = input.begin(); i != input.end();)
    {
        if (*i == ' ')
        {
            output.push_back(*i);
            i++;
            continue;
        }
        while (*i != ' ' && i != input.end())
        {
            word.push_back(*i);
            i++;
        }
        for (auto j = word.rbegin(); j != word.rend(); j++)
        {
            output.push_back(*j);
        }
        if (longest.size() <= word.size())
        {
            longest.clear();
            for (auto j = word.rbegin(); j != word.rend(); j++)
            {
                longest.push_back(*j);
            }
        }
        word.clear();
    }

    std::cout << output << std::endl;
    std::cout << longest << std::endl;

    if (longest.size() % 2 == 0)
    {
        std::cout << longest.at(longest.size() / 2 - 1) << std::endl;
    }
    std::cout << longest.at(longest.size() / 2) << std::endl;
}
