#include <iostream>
#include <list>
#include <string>

struct Student
{
    std::string name;
    std::string major;
    int id;
};
int search_student(const std::list<Student> &students, const Student &target);

int main()
{
    std::list<Student> students;

    std::string command;
    while (true)
    {
        std::cin >> command;
        if (command == "Add")
        {
            Student student;
            std::cin >> student.name;
            std::cin >> student.major;
            std::cin >> student.id;
            students.push_back(student);
            std::cout << "Added Successfully" << std::endl;
        }
        else if (command == "Search")
        {
            Student target;
            std::cin >> target.name;
            std::cin >> target.major;
            int id = search_student(students, target);
            if (id == -1)
            {
                std::cout << "No Record found" << std::endl;
            }
            else
            {
                std::cout << "Student Number:" << id << std::endl;
            }
        }
        else if (command == "Quit")
        {
            std::cout << "Bye" << std::endl;
            break;
        }
    }

    return 0;
}

int search_student(const std::list<Student> &students, const Student &target)
{
    for (auto student : students)
    {
        if (student.name == target.name && student.major == target.major)
        {
            return student.id;
        }
    }
    return -1;
}