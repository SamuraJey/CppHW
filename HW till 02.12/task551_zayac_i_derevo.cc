#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    double R, r, h, b; // название переменных как в задаче. Радиус большой, рад.маленький, высота, расстояние
    cin >> R >> r >> h >> b;

    if (b + r >= R)
    {
        cout << 'Y' << 'E' << 'S';
        return 0;
    }

    if (sqrt(pow(R, 2) - pow(r, 2)) + (b - r) >= h)
    {
        cout << "YES";
        return 0;
    }
    else
    {
        cout << "NO";
        return 0;
    }
    
    return 0;
}