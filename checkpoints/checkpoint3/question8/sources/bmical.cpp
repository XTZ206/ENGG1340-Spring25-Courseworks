#include <iostream>

int main(void)
{
    double weight, height, bmi;
    std::cin >> weight >> height;
    bmi = weight / (height * height);
    std::cout << "Your BMI = " << bmi << std::endl;
    std::cout << "BMI VALUES" << std::endl
              << "Underweight: less than 18.5" << std::endl
              << "Normal: between 18.5 and 24.9" << std::endl
              << "Overweight: between 25 and 29.9" << std::endl
              << "Obese: 30 or greater" << std::endl;

    return 0;
}