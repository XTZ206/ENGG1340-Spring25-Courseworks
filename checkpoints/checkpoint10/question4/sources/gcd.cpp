#include <iostream>
using namespace std;

int main()
{
    int n1 = 32;
    int n2 = 8;
    while (n1 != n2)
    {
        if (n1 > n2)
        {
            n1 -= n2;
        }
        else
        {
            n2 -= n1;
        }
    }
    cout << "GCD = " << n1 << endl;
    return 0;
}