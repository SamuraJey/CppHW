#include <algorithm>
#include <iostream>

using namespace std;

bool intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) // Функция, проверяющая пересечение двух отрезков
{
    long long v1, v2, v3, v4;

    v1 = static_cast<long long>(x4 - x3) * (y1 - y3) - static_cast<long long>(y4 - y3) * (x1 - x3); // static_cast<long long> - преобразование типа к long long
    v2 = static_cast<long long>(x4 - x3) * (y2 - y3) - static_cast<long long>(y4 - y3) * (x2 - x3); // что бы избежать переполнения int и не потерять точность при вычислениях
    v3 = static_cast<long long>(x2 - x1) * (y3 - y1) - static_cast<long long>(y2 - y1) * (x3 - x1);
    v4 = static_cast<long long>(x2 - x1) * (y4 - y1) - static_cast<long long>(y2 - y1) * (x4 - x1);

    if (v1 * v2 == 0 && v3 * v4 == 0) // Eсли отрезки лежат на одной прямой
    {
        if (y1 == y2) // Если отрезки параллельны оси OX
        {
            if (x1 > x2) // Если первая точка первого отрезка лежит правее второй
            {
                swap(x1, x2); // Меняем местами координаты
                swap(y1, y2); // Первой и второй точки
            }
            if (x3 > x4) // Если первая точка второго отрезка лежит правее второй
            {
                swap(x3, x4);
                swap(y3, y4);
            }
            return x3 <= x2 && x4 >= x1; // Пересекаются ли отрезки  на горизонтальной прямой
        }
        else
        {
            if (y1 > y2) // Если первая точка первог отрезка лежит выше второй
            {
                swap(x1, x2);
                swap(y1, y2);
            }
            if (y3 > y4) // Если первая точка второго отрезка лежит выше второй
            {
                swap(x3, x4);
                swap(y3, y4);
            }
            return y3 <= y2 && y4 >= y1; // Пересекаются ли отрезки на вертикальной прямой
        }
    }

    return v1 * v2 <= 0 && v3 * v4 <= 0; // Пересекаются ли отрезки
}

// пример использования функции
int main()
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    if (intersection(x1, y1, x2, y2, x3, y3, x4, y4))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}