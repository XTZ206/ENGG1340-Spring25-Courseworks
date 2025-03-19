#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char name[100];
    char position[100];
    int salary;
};
typedef struct Employee Employee;

void set_employee(char name[], char position[], int salary, Employee *employee)
{
    strcpy(employee->name, name);
    strcpy(employee->position, position);
    employee->salary = salary;
}

void show_info(Employee employee)
{
    printf("Name: %s\n", employee.name);
    printf("Position: %s\n", employee.position);
    printf("Salary: %d\n", employee.salary);
}

int main(void)
{
    int employee_num;
    scanf("%d", &employee_num);
    Employee *employees = (Employee *)malloc(employee_num * sizeof(Employee));
    char name[100];
    char position[100];
    int salary;

    for (int i = 0; i < employee_num; i++)
    {
        scanf("%s%s%d", name, position, &salary);
        set_employee(name, position, salary, &employees[i]);
    }

    for (int i = 0; i < employee_num; i++)
    {
        show_info(employees[i]);
    }

    free(employees);
    return 0;
}