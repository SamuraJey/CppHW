#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum napr { downn, rightn, upn, leftn };
int ss[101][101] = { 0 };
int main() 
{
    int n, m;
    cin >> n >> m;
    napr bugn = downn;   // начальное направление движения
    vector <string> s(n+1);
    getline(cin, s[0]);
    int steps = 0;
    for (int z = 1; z <= n; z++) 
    {
        getline(cin,s[z]); s[z] = '@' + s[z];
    }
    int x = 2, y = 2, olddy = 1, olddx = 0;
    ss[2][2] = 1;
    while (!(x == m - 1 && y == n - 1)) 
    {
            int dx, dy;
            napr kuda; int z = 2000000;
            if (s[y + 1][x] != '@') if (ss[y + 1][x] < z) 
            {
                z = ss[y + 1][x]; 
                kuda = downn;
                dx = 0; dy = 1;
            }
            if (s[y][x + 1] != '@') if (ss[y][x + 1] < z)
            {
                z = ss[y][x + 1];
                kuda = rightn;
                dx = 1; dy = 0;
            };
            if (s[y - 1][x] != '@') if (ss[y - 1][x] < z)
            {
                z = ss[y - 1][x];
                kuda = upn;
                dy = -1; dx = 0;
            }
            if (s[y][x - 1] != '@') if (ss[y][x - 1] < z)
            {
                z = ss[y][x - 1];
                kuda = leftn;
                dx = -1; dy = 0;
            }
            if (steps > 10000000 || z == 2000000) 
            {
                cout << -1;
                return 0;
            }
            // совпадает ли направление движения с минимумом
            if (kuda == bugn)
            {
                x += dx; y += dy;
                steps++; ss[y][x]++;
            }
            else {
                if (s[y+olddy][x+olddx]!='@' && ss[y + dy][x + dx] == ss[y + olddy][x + olddx])
                { // не совпало, но мы продолжаем движение в старом направлении
                    x += olddx; y += olddy; steps++; kuda = bugn; ss[y][x]++;
                }
                else { // здесь нужно повернуть
                    bugn = kuda; x += dx; y += dy; steps++; ss[y][x]++;
                    olddx = dx; olddy = dy; // запомним последнее смещение
                }
            }
    }
    cout << steps;
    return 0;
}