#include <iostream>

using namespace std;

int main()
{
    int num, pow;
    int res = 0;

    cout << "Enter number:";
    cin >> num;
    cout << "Enter power:";
    cin >> pow;

    if (pow == 0)
    {
        res = 1;
    }
    else if (pow == 1)
    {
        res = num;
    }
    else
    {
        res = num;
        for (int i = 0; i < pow - 1; i++)
        {
            res = res * num;
        }
    }

    cout << "Result:" << res << endl;
}