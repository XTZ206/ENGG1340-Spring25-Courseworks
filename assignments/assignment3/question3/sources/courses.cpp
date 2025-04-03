#include <iostream>

struct Course
{
    int id;
    int start;
    int end;
    Course *next;
    Course *prev;
};

// Courses are stored in a doubly linked list
// The list is sorted by start time
static Course *courses = nullptr;

Course *find_course(int id)
{
    Course *curr = courses;
    while (curr != nullptr)
    {
        if (curr->id == id)
        {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void print_courses(void)
{
    Course *curr = courses;
    if (curr == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    while (curr != nullptr)
    {
        std::cout << curr->id << ": " << curr->start << " - " << curr->end << std::endl;
        curr = curr->next;
    }
}

bool delete_course(int id)
{
    Course *curr = find_course(id);
    if (curr == nullptr)
    {
        return false;
    }
    if (curr->prev != nullptr)
    {
        curr->prev->next = curr->next;
    }
    else
    {
        courses = curr->next;
    }
    if (curr->next != nullptr)
    {
        curr->next->prev = curr->prev;
    }
    delete curr;
    return true;
}

bool insert_course(int id, int start, int end)
{
    Course *new_course = new Course{id, start, end, nullptr, nullptr};

    // Check for overlapping courses
    for (Course *curr = courses; curr != nullptr; curr = curr->next)
    {
        if ((start < curr->end && end > curr->start) || (end > curr->start && start < curr->end))
        {
            delete new_course;
            return false;
        }
    }

    // Insert at the beginning
    if (courses == nullptr || start < courses->start)
    {
        new_course->next = courses;
        if (courses != nullptr)
        {
            courses->prev = new_course;
        }
        courses = new_course;
        return true;
    }

    // Otherwise, find the correct position to insert
    Course *curr = courses;
    while (curr->next != nullptr && curr->next->start < start)
    {
        curr = curr->next;
    }
    new_course->next = curr->next;
    new_course->prev = curr;
    if (curr->next != nullptr)
    {
        curr->next->prev = new_course;
    }
    curr->next = new_course;

    return true;
}

bool update_course(int id, int start, int end)
{
    Course *temp = find_course(id);
    if (temp == nullptr)
    {
        return false;
    }

    // Check for overlapping courses
    for (Course *curr = courses; curr != nullptr; curr = curr->next)
    {
        if (curr->id != id && ((start < curr->end && end > curr->start) || (end > curr->start && start < curr->end)))
        {
            return false;
        }
    }

    // Remove the old course
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    if (temp == courses)
    {
        courses = temp->next;
    }
    delete temp;

    // Insert the new course
    return insert_course(id, start, end);
}

int main(void)
{
    for (std::string command; std::cin >> command;)
    {

        if (command == "quit")
        {
            break;
        }
        if (command == "print")
        {
            print_courses();
            continue;
        }

        int id;
        std::cin >> id;

        if (command == "delete")
        {
            delete_course(id);
            continue;
        }

        int start;
        int end;
        std::cin >> start;
        std::cin >> end;

        if (command == "insert")
        {
            if (!insert_course(id, start, end))
            {
                std::cout << "false" << std::endl;
            }
            continue;
        }
        if (command == "update")
        {
            if (!update_course(id, start, end))
            {
                std::cout << "false" << std::endl;
            }
            continue;
        }
    }
    return 0;
}
