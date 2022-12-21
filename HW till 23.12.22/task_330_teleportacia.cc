#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - x2) == abs(y1 - y2)) // если лежит на одной диагоали то можем за 1 шаг дойти
    {
        cout << 1; 
        return 0;
    }
    if ((abs(x1 - x2) + abs(y1 - y2)) % 2 == 0)
    {
        cout << 2;
    }
    else cout << 0;
    
    return 0;
}