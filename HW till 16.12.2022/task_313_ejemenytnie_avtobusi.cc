#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, delta, maximum = 0;
    cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                delta = j - i;
                break;
            }
        }
        if (delta > maximum)
        {
            maximum = delta;
        }
    }
    cout << maximum << endl;

    return 0;
}