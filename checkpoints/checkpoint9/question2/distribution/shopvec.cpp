#include <iostream>
#include <vector>
#include <string>
#include <iterator>

void print_items(const std::vector<std::string> &items);

int main(void)
{
    std::vector<std::string> items;
    print_items(items);

    items.push_back("eggs");
    items.push_back("milk");
    items.push_back("sugar");
    items.push_back("chocolate");
    items.push_back("flour");
    print_items(items);

    items.pop_back();
    print_items(items);

    items.push_back("coffee");
    print_items(items);

    for (auto iter = items.begin(); iter != items.end(); ++iter)
    {
        if (*iter == "sugar")
        {
            *iter = "honey";
            break;
        }
    }
    print_items(items);

    for (auto iter = items.begin(); iter != items.end(); ++iter)
    {
        if (*iter == "milk")
        {
            items.erase(iter);
            break;
        }
    }
    print_items(items);

    return 0;
}

void print_items(const std::vector<std::string> &items)
{
    std::cout << "Items:";
    for (int i = 0; i < items.size(); i++)
    {
        std::cout << " ";
        std::cout << items[i] << (i == items.size() - 1 ? "" : ",");
    }
    std::cout << std::endl;
}