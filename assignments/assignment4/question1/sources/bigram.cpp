#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{

    std::vector<std::string> tokens;
    std::vector<std::string> bigrams;
    std::vector<int> counts;
    std::string most_common_bigram;
    int most_common_count = 0;

    // Read the input and store the tokens
    for (std::string token; std::cin >> token;)
    {
        tokens.push_back(token);
    }

    // Count the bigrams
    for (std::string &token : tokens)
    {
        for (auto iter = token.begin(); iter != token.end() - 1; ++iter)
        {
            std::string bigram = std::string(iter, iter + 2);
            int index = std::distance(bigrams.begin(), std::find(bigrams.begin(), bigrams.end(), bigram));
            if (index == bigrams.size())
            {
                bigrams.push_back(bigram);
                counts.push_back(1);
            }
            else
            {
                counts.at(index)++;
            }
            if (counts.at(index) > most_common_count)
            {
                most_common_count = counts.at(index);
            }
        }
    }

    // No bigrams found
    if (bigrams.empty())
    {
        return 0;
    }

    // Print the tokens where the most frequent bigram is in it only once
    most_common_bigram = bigrams.at(std::distance(counts.begin(), std::find(counts.begin(), counts.end(), most_common_count)));

    std::vector<std::string> printed_tokens;
    for (const auto &token : tokens)
    {
        if (token.find(most_common_bigram) != std::string::npos && std::find(printed_tokens.begin(), printed_tokens.end(), token) == printed_tokens.end())
        {
            std::cout << token << std::endl;
            printed_tokens.push_back(token);
        }
    }

    return 0;
}
