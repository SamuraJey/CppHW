#include <math.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    double x1, x2, x3, y1, y2, y3, dist1, dist2, dist3, x4, y4;
    bool f;
    f = false;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    dist1 = hypot(x1 - x2, y1 - y2); //hypot аналогична записи sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    dist2 = hypot(x3 - x2, y3 - y2); // т.е. возвращает корень из суммы квадратов
    dist3 = hypot(x1 - x3, y1 - y3);
    
    if ((dist1 == dist2 && hypot(dist1, dist2) == dist3) || (dist1 == dist3 && hypot(dist1, dist3) == dist2) || ((dist2 == dist3 && hypot(dist2, dist3) == dist1))) 
    {
        f = true;
    }
    if (f)
    {
        if (x1 == x2) 
        {
            x4 = x3;
        }
        if (y1 == y2)
        {
            y4 = y3;
        }
        if (x2 == x3) 
        {
            x4 = x1;
        }
        if (y2 == y3) 
        {
            y4 = y1;
        }
        if (x3 == x1) 
        {
            x4 = x2;
        }
        if (y3 == y1)
        {
            y4 = y2;
        }
        cout << "Квадрат возможен " << endl << "(x4,y4) = " << '(' << x4 << ',' << y4 << ')' << endl;
    }
    else 
    {
        cout << "Квадрат невозможен " << endl;
    }

    return 0;
}

/*
https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_609e4aa9-0d76-4e33-90a8-b3340b266391
Cond6. * Заданы координаты трех точек на плоскости. Являются ли они вершинами квадрата? Если да, то найти координаты четвертой вершины.
*/