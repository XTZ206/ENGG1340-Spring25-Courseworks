#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string code;
    string name;
    string lecturer;
};

int main()
{
    string input;
    cin >> input;
    Course courses[100];
    int count = 0;

    while (input != "exit")
    {
        if (input == "add")
        {
            Course course;
            cin >> course.code >> course.name >> course.lecturer;
            courses[count] = course;
            count++;
        }
        if (input == "show")
        {
            string code;
            cin >> code;
            for (int i = 0; i < count; i++)
            {
                if (courses[i].code == code)
                {
                    cout << "Name: " << courses[i].name << ", ";
                    cout << "Lecturer: " << courses[i].lecturer << endl;
                }
            }
        }
        cin >> input;
    }
    return 0;
}