#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(void)
{
    std::ifstream fin;
    std::ofstream fout;

    std::string date;
    double temperatures[24];
    double average = 0;

    fin.open("temperature.txt");
    fout.open("average.txt");

    while (fin >> date)
    {
        average = 0;
        for (int i = 0; i < 24; i++)
        {
            fin >> temperatures[i];
            average += temperatures[i] / 24;
        }
        fout << date << " " << std::fixed << std::setprecision(1) << average << std::endl;
    }

    fin.close();
    fout.close();
}