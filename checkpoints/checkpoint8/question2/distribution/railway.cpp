#include <iostream>
#include <string>
#include <cstdlib>

struct Car
{
    std::string id;
    Car *next;
};

void appendCar(Car *&head, std::string id);
void printTrain(Car *&head);

int main(void)
{
    Car *head = NULL;
    int n;
    std::cin >> n;
    std::string id;
    for (int i = 0; i < n; i++)
    {
        std::cin >> id;
        appendCar(head, id);
    }
    printTrain(head);
    return 0;
}

void appendCar(Car *&head, std::string id)
{
    Car *newCar = new Car;
    newCar->id = id;
    newCar->next = NULL;
    if (head == NULL)
    {
        head = newCar;
    }
    else
    {
        Car *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newCar;
    }
}

void printTrain(Car *&head)
{
    Car *current = head;
    while (current != NULL)
    {
        if (current->next != NULL)
        {
            std::cout << current->id << ", ";
        }
        else
        {
            std::cout << current->id;
        }
        current = current->next;
    }
    std::cout << std::endl;
}