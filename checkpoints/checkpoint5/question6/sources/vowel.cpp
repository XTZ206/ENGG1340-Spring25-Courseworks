#include <iostream>
using namespace std;

bool isVowel(char c)
{
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    int n;
    int numVowel = 0;
    char c;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        if (isVowel(c))
            numVowel++;
    }

    cout << "Number of vowels = " << numVowel << endl;

    return 0;
}