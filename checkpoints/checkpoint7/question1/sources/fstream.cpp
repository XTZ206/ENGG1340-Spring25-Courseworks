#include <fstream>
#include <iostream>

int main(void)
{

    std::ofstream cfile;
    cfile.open("c.txt", std::ios::ate | std::ios::binary);
}