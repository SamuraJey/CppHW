#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x2 < y1 && y2 < y1) && (x2 >= x1))
    {
        cout << "Вложенный " << x2 << " " << y2 << endl;
        return 0;
    }

    if (x2 == x1 && y1 == y2)
    {
        cout << "Совпадают: " << x2 << " " << y2 << endl;
        return 0;
    }

    if (x2 < y1 && y2 > y1)
    {
        cout << "Пересекаются: " << x2 << " " << y1 << endl;
        return 0;
    }

    if (y2 > x1 && x2 < x1)
    {
        cout << "Пересекаются " << x1 << " " << y2 << endl;
        return 0;
    }

    cout << "Не пересекаются" << endl;
    


    return 0;
}


/*
https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_609e4aa9-0d76-4e33-90a8-b3340b266391
Пересечение двух отрезков [A,B] и [C,D] на числовой прямой. Найти красивое решение, то есть наиболее ясное и краткое.
*/