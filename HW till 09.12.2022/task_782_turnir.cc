#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long n;
    int answ = 0;
    cin >> n;

    if (n > 3)
    {
        answ++;
    }

    while (n > 1)
    {
        answ += n / 2;
        n = n / 2 + n % 2;
    }

    cout << answ;
    return 0;
}
