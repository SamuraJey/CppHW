#include <iostream>
#include <string>

using namespace std;

int main()
{
    char a[104][104] = { 0 };
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int x = 51, y = 51;
    string s;
    int  counter = 0, direction = 0;

    cin >> s;
    a[x][y] = 1;
    for (int z = 0; z < s.length(); z++)
    {
        if (s[z] == 'R')
        {
            direction = (direction + 5) % 4;
        }
        if (s[z] == 'L')
        {
            direction = (direction + 3) % 4;
        }
        if (s[z]=='S')
        {
            x += dx[direction];
            y += dy[direction];
            if (a[x][y] == 1) 
            {
                cout << counter + 1;
                return 0;
            }
            else 
            {
                a[x][y] = 1;
                counter++;
            }
        }
    }
    cout << -1;
    return 0;
}