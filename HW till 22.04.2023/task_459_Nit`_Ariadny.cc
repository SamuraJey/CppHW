#include <iostream>
#include <string>
#include <vector>

using namespace std;

void recalc(int x, int y, vector<vector < int>> &a)
{
    // пересчет ячеек при пересечении нуля
    if (a[x - 1][y] > a[x][y] + 1 && a[x - 1][y] != 1000)
    {
        // проверка севера
        a[x - 1][y] = a[x][y] + 1;
    }
    if (a[x - 2][y] > a[x][y] + 2 && a[x - 1][y] != 1000)
    {
        a[x - 2][y] = a[x][y] + 2;
        recalc(x - 2, y, a);
    }
    if (a[x][y + 1] > a[x][y] + 1 && a[x][y + 1] != 1000)
    {
        // проверка востока
        a[x][y + 1] = a[x][y] + 1;
    }
    if (a[x][y + 2] > a[x][y] + 2 && a[x][y + 2] != 1000)
    {
        a[x][y + 2] = a[x][y] + 2;
        recalc(x, y + 2, a);
    }
    if (a[x + 1][y] > a[x][y] + 1 && a[x + 1][y] != 1000)
    {
        // проверка юга
        a[x + 1][y] = a[x][y] + 1;
    }
    if (a[x + 2][y] > a[x][y] + 2 && a[x + 1][y] != 1000)
    {
        a[x + 2][y] = a[x][y] + 2;
        recalc(x + 2, y, a);
    }

    if (a[x][y - 1] > a[x][y] + 1 && a[x][y - 1] != 1000)
    {
        // проверка запада
        a[x][y - 1] = a[x][y] + 1;
    }

    if (a[x][y - 2] > a[x][y] + 2 && a[x][y - 1] != 1000)
    {
        a[x][y - 2] = a[x][y] + 2;
        recalc(x, y - 2, a);
    }

    return;
}

int main()
{
    string s = "";

    cin >> s;
    // проверим размеры необходимого массива
    int nN = 0, nE = 0, nS = 0, nW = 0;

    for (int z = 0; z < s.size(); z++)
    {
        switch (s[z])
        {
            case 'N':
                nN++;
                break;

            case 'E':
                nE++;
                break;

            case 'S':
                nS++;
                break;

            case 'W':
                nW++;
                break;
        }
    }

    int sizeSN = (nN + nS) *2 + 6;
    int sizeEW = (nW + nE) *2 + 6;
    vector<vector < int>> a(sizeSN, vector<int> (sizeEW, 1000));
    int curX = nN *2 + 3, curY = nW *2 + 3;	// исходная точка Тесея
    int len = 0;
    a[curX][curY] = len;	// длина кратчайшего пути
    for (int z = 0; z < s.size(); z++)
    {
        // рисуем путь героя
        switch (s[z])
        {
            case 'N':// на Север
                curX--;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len;	// помечаем проход

                }
                curX--;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len;	// помечаем комнату
                }

                break;
            case 'E':	// на Восток
                curY++;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len;	// помечаем проход

                }
                curY++;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len;

                }
                break;

            case 'S': // На Юг
                curX++;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len;
                }

                curX++;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len;
                }
                break;

            case 'W':	// на Запад
                curY--;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len; 

                }
                curY--;
                len++;
                if (a[curX][curY] == 1000)
                {
                    a[curX][curY] = len;
                }
                break;
        }
    }

    // Возможно, мы проскочили через исходную точку и теперь нужно пересчитать расстояния
    recalc(nN *2 + 3, nW *2 + 3, a);
    // теперь ищем путь обратно
    string sBack = "";
    while (a[curX][curY] > 0)
    {
        char step = 'N';
        int minL = a[curX][curY];
        // ищем кратчайший путь
        if (minL > a[curX - 2][curY] && a[curX - 1][curY] != 1000)
        {
            // проверяем Север
            step = 'N';
            minL = a[curX - 2][curY];
        }

        if (minL > a[curX][curY + 2] && a[curX][curY + 1] != 1000)
        {
            // проверяем Восток
            step = 'E';
            minL = a[curX][curY + 2];
        }

        if (minL > a[curX + 2][curY] && a[curX + 1][curY] != 1000) // проверяем Юг
        {
            step = 'S';
            minL = a[curX + 2][curY];
        }
        if (minL > a[curX][curY - 2] && a[curX][curY - 1] != 1000) // проверяем Запад
        {
            step = 'W';
            minL = a[curX][curY - 2];
        }
        // делаем шаг
        sBack += step; // добавляем в строку шаг
        switch (step) // меняем координаты в зависимости от направления движения
        {
            case 'N':
                curX -= 2;
                break;
            case 'E':
                curY += 2;
                break;
            case 'S':
                curX += 2;
                break;
            case 'W':
                curY -= 2;
                break;
        }
    }
    cout << sBack;
    return 0;
}