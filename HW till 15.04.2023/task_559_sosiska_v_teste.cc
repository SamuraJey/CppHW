#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    double diameter, radius, area, left, right, middle, midArea, theta, pi;
    pi = 3.14159265358979323846; // ОНО НЕ ПРИНИМАЕТ M_PI из cmath аааааа
    cin >> diameter >> radius >> n;

    for (int i = 1; i < n; i++)
    {
        area = i * (pi * radius * radius + 2 * radius * diameter) / n; // вычисление площади сектора и двух треугольников
        left = 0;
        right = 2 * radius + diameter; // определение границ отрезка методом бисекции
        for (int j = 0; j < 64; j++)
        {
            middle = (left + right) / 2;
            if (middle < radius) // если точка лежит внутри окружности
            {
                theta = 2 * acos((radius - middle) / radius);
                midArea = radius * radius / 2 * (theta - sin(theta));
            }
            else // если точка лежит вне окружности
            {
                if (middle <= radius + diameter) // если точка лежит на дуге окружности
                {
                    midArea = pi * radius * radius / 2 + (middle - radius) * 2 * radius; // вычисление площади сектора и двух треугольника
                }
                else
                {
                    theta = 2 * acos((radius - (2 * radius + diameter - middle)) / radius); // вычисление угла
                    midArea = (pi * radius * radius + 2 * radius * diameter) - radius * radius/2 * (theta - sin(theta)); // вычисление площади сектора и двух треугольников
                }
            }

            if (midArea > area) // если площадь больше, то сдвигаем правую границу
            {
                right = middle;
            }
            else // если площадь меньше, то сдвигаем левую границу
            {
                left = middle;
            }
        }
        cout << fixed << setprecision(6);
        cout << (left + right) / 2 << endl;
    }
}
