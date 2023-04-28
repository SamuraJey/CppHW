/*
1301. Куб в лабиринте - http://acm.timus.ru/problem.aspx?num=1301

Программа создает лабиринт в форме куба и находит самый короткий путь от одной точки к другой.
Она использует графы и поиск в глубину (DFS) для обхода лабиринта.
Лабиринт представлен в виде матрицы видимости граней куба.
Программа проверяет возможность перемещения из одной точки в другую и определяет конфигурацию куба после поворота и переворота грани.
Она также подсчитывает самую короткую длину пути с помощью матрицы с самой короткой длиной пути.
В конце программа выводит длину самого короткого пути или сообщение "No solution", если путь не найден.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

// создаем глобальные переменные туточки
vector <int> edgeNeighbors(255); // Соседний край индексного ребра
unsigned int shortestPaths[255][11][11]; // Матриа с самой короткой длиной пути
bool visibleFaces[11][11][11][11]; // Матрица видимости граней куба
int m, n; // Размеры лабиринта
struct point { int x, y; }; // Координаты точки в лабиринте

// Проверяет является ли { sx, sy } -> { x, y } допустимым ходом
bool isValidMove(int sx, int sy, int x, int y)
{
    return x <= m && y <= n && x > 0 && y > 0 && visibleFaces[sx][sy][x][y];
}

// Возвращает конфигурацию, полученную путем поворота этой конфигурации на 90*deg градусов. 
// Конфигурация определяется идентификатором левого края верхней поверхности куба
int getRotatedConfiguration(int dfsStack, int deg)
{
    return (dfsStack + deg) % 4 + (dfsStack & 240);
}

// Возвращает грань, полученную путем переворачивания этой грани вдоль заданного направления
int getFlippedFace(int dfsStack, int directions)
{
    if (directions == 0) // влево
    {
        return edgeNeighbors[getRotatedConfiguration(dfsStack, 2)];
    }
    else if (directions == 1) // вверх
    {
        return getRotatedConfiguration(edgeNeighbors[getRotatedConfiguration(dfsStack, 3)], 3);
    }
    else if (directions == 2) // вправо
    {
       return getRotatedConfiguration(edgeNeighbors[dfsStack], 2); 
    }
    else if (directions == 3) // вниз
    {
        return getRotatedConfiguration(edgeNeighbors[getRotatedConfiguration(dfsStack, 1)], 1);
    }
    return 0;
}

int main()
{
    string inputStr;
    bool isVertical;
    int a, b, c, d, x, y;

    memset(visibleFaces, true, sizeof(visibleFaces)); // эффективно заполняем массив значениями true, все грани видны изначально
    memset(shortestPaths, 255, sizeof(shortestPaths)); // эффективно заполняем массив значениями 255, все расстояния изначально бесконечны

    edgeNeighbors[160] = 177; edgeNeighbors[161] = 243; edgeNeighbors[162] = 209; edgeNeighbors[163] = 193; edgeNeighbors[208] = 194; edgeNeighbors[209] = 162;
    edgeNeighbors[210] = 242; edgeNeighbors[211] = 226; edgeNeighbors[192] = 178; edgeNeighbors[193] = 163; edgeNeighbors[194] = 208; edgeNeighbors[195] = 225;
    edgeNeighbors[176] = 240; edgeNeighbors[177] = 160; edgeNeighbors[178] = 192; edgeNeighbors[179] = 224; edgeNeighbors[224] = 179; edgeNeighbors[225] = 195; 
    edgeNeighbors[226] = 211; edgeNeighbors[227] = 241; edgeNeighbors[240] = 176; edgeNeighbors[241] = 227; edgeNeighbors[242] = 210; edgeNeighbors[243] = 161;
    stack<pair<point, int>, vector<pair<point, int>>> dfsStack; // dfs stack

    cin >> m >> n >> a >> b >> c >> d;
    while(cin >> inputStr)
    {
        if(inputStr[0] == 'v')
        {
            isVertical = true;
        }
        else if(inputStr[0] == 'h')
        {
            isVertical = false;
        }
        else
        {
            x = stoi(inputStr);
            cin >> y;
            if(isVertical)
            {
                visibleFaces[x+1][y][x][y] = visibleFaces[x][y][x+1][y] = false;
            }
            else
            {
                visibleFaces[x][y][x][y+1] = visibleFaces[x][y+1][x][y] = false;
            }
        }
    }

    // Dfs
    const point directions[4] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};
    dfsStack.push({{ a, b }, 160 });
    shortestPaths[160][a][b] = 0;
    while(!dfsStack.empty())
    {
        auto currentPosition = dfsStack.top().first;
        auto currentConfiguration = dfsStack.top().second;
        dfsStack.pop();
        for(int i = 0; i < 4; i++)
        {
            auto d = directions[i];
            point pd = { currentPosition.x + d.x, currentPosition.y + d.y };
            if(isValidMove(currentPosition.x, currentPosition.y, pd.x, pd.y))
            {
                auto newConfiguration = getFlippedFace(currentConfiguration, i);
                if(shortestPaths[newConfiguration][pd.x][pd.y] > shortestPaths[currentConfiguration][currentPosition.x][currentPosition.y])
                {
                    shortestPaths[newConfiguration][pd.x][pd.y] = shortestPaths[currentConfiguration][currentPosition.x][currentPosition.y] + 1;
                    dfsStack.push({{pd.x, pd.y}, newConfiguration });
                }
            }
        }
    }
    unsigned int minPathLength = 999999999;
    for(int i = 0; i < 4; i++)
    {
        minPathLength = min(minPathLength, shortestPaths[160 + i][c][d]);
    }
    if(minPathLength == 999999999)
    {
        cout << "No solution";
    }
    else
    {
        cout << minPathLength;
    }
}