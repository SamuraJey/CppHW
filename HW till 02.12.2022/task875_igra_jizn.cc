#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    int n,m,k;
    cin >> n >> m >> k;
    vector <string> l(n),l1(n);

    for (int i = 0; i < n; i++) // заполняем даннными
    { 
        cin >> l[i];
        l1[i] = l[i]; // делаем копию
    }

    for (int t = 0; t < k; t++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int x = 0; x < m; x++)
            {
                int s = 0; // для считания соседей
                s += l[(i + n - 1) % n][(x + m - 1) % m] == '*';
                s += l[(i + n - 1) % n][x] == '*';
                s += l[(i + n - 1) % n][(x + m + 1) % m] == '*';
                s += l[i][(x + m - 1) % m] == '*';
                s += l[i][(x + m + 1) % m] == '*';
                s += l[(i + n + 1) % n][(x + m - 1) % m] == '*';
                s += l[(i + n + 1) % n][x] == '*';
                s += l[(i + n + 1) % n][(x + m + 1) % m] == '*';
                if (s < 2 || s>3)
                {
                    l1[i][x] = '.'; // dead
                }
                if (s == 3) 
                {
                    l1[i][x] = '*'; // alive
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            l[i] = l1[i]; // делаем копию
        }
    }
    for (auto i : l)
    {
        cout << i << endl;
    }

    return 0;
}