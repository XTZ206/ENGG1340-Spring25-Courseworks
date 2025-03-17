#include <iostream>
using namespace std;

const int N = 1000;

bool isPerfect(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += (n % i == 0) ? i : 0;
    }
    return n == sum;
}

int main()
{
    cout << "For the integers from 1 to " << N << ":\n";

    for (int j = 2; j <= N; ++j)
        if (isPerfect(j))
            cout << j << " is perfect\n";

    cout << endl;

    return 0;
}