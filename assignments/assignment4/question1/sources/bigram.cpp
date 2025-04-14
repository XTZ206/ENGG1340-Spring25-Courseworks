#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

int main(void)
{

    std::vector<std::string> tokens;
    std::unordered_map<std::string, int> bigrams;

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
            if (bigrams.find(bigram) == bigrams.end())
            {
                bigrams[bigram] = 1;
            }
            else
            {
                bigrams[bigram]++;
            }
        }
    }

    // Find the most frequent bigram
    std::string most_frequent_bigram = "";
    int most_frequent_count = 0;

    for (const auto &pair : bigrams)
    {
        if (pair.second > most_frequent_count)
        {
            most_frequent_count = pair.second;
            most_frequent_bigram = pair.first;
        }
    }

    // If there is no bigram
    if (most_frequent_bigram == "")
    {
        return 0;
    }

    // Print the tokens where the most frequent bigram is in it only once
    std::set<std::string> printed_tokens;
    for (const auto &token : tokens)
    {
        if (printed_tokens.find(token) == printed_tokens.end() &&
            token.find(most_frequent_bigram) != std::string::npos)
        {
            printed_tokens.insert(token);
            std::cout << token << std::endl;
        }
    }

    return 0;
}