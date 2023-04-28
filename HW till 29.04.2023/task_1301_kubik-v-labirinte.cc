/* 1301. Cube in Labyrinth - http://acm.timus.ru/problem.aspx?num=1301
 *
 * Strategy:
 * Depth-first search through the maze while recording the shortest path to each position for
 * each configuration of the cube, terminating any branch whenever a shorter path than the
 * current was reached for the position and configuration of the branch.
 *
 * Performance:
 * O(XY), runs the tests in 0.001s using 404KB memory.
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
int N[255]; // Соседний край индексного ребра
unsigned int A[255][11][11]; // Матриа с самой короткой длиной пути
bool V[11][11][11][11]; // Матрица видимости граней куба
int m, n; // Размеры лабиринта
struct point { int x, y; }; // Координаты точки в лабиринте

// Проверяет является ли { sx, sy } -> { x, y } допустимым ходом
bool valid(int sx, int sy, int x, int y)
{
    return x <= m && y <= n && x > 0 && y > 0 && V[sx][sy][x][y];
}

// Возвращает конфигурацию, полученную путем поворота этой конфигурации на 90*deg градусов. 
// Конфигурация определяется идентификатором левого края верхней поверхности куба
int rotate(int dfsStack, int deg)
{
    return (dfsStack + deg) % 4 + (dfsStack & 240);
}

// Возвращает грань, полученную путем переворачивания этой грани вдоль заданного направления
int flip(int dfsStack, int dir)
{
    if (dir == 0) // влево
    {
        return N[rotate(dfsStack, 2)];
    }
    else if (dir == 1) // вверх
    {
        return rotate(N[rotate(dfsStack, 3)], 3);
    }
    else if (dir == 2) // вправо
    {
       return rotate(N[dfsStack], 2); 
    }
    else if (dir == 3) // вниз
    {
        return rotate(N[rotate(dfsStack, 1)], 1);
    }
    return 0;
}

int main()
{
    string str;
    bool vertical;
    int a, b, c, d, x, y;
    memset(V, true, sizeof(V)); // эффективно заполняем массив значениями true, все грани видны изначально
    memset(A, 255, sizeof(A)); // эффективно заполняем массив значениями 255, все расстояния изначально бесконечны

    N[160] = 177; N[161] = 243; N[162] = 209; N[163] = 193; N[208] = 194; N[209] = 162;
    N[210] = 242; N[211] = 226; N[192] = 178; N[193] = 163; N[194] = 208; N[195] = 225;
    N[176] = 240; N[177] = 160; N[178] = 192; N[179] = 224; N[224] = 179; N[225] = 195; 
    N[226] = 211; N[227] = 241; N[240] = 176; N[241] = 227; N[242] = 210; N[243] = 161;
    stack<pair<point, int>, vector<pair<point, int>>> dfsStack; // dfs stack



    // Read the input
    std::cin >> m >> n >> a >> b >> c >> d;
    while(cin >> str)
    {
        if(str[0] == 'v')
        {
            vertical = true;
        }
        else if(str[0] == 'h')
        {
            vertical = false;
        }
        else
        {
            x = std::stoi(str);
            std::cin >> y;
            if(vertical)
            {
                V[x+1][y][x][y] = V[x][y][x+1][y] = false;
            }
            else
            {
                V[x][y][x][y+1] = V[x][y+1][x][y] = false;
            }
        }
    }

    // Dfs
    const point dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    dfsStack.push( { { a, b }, 160 } );
    A[160][a][b] = 0;
    while(!dfsStack.empty())
    {
        auto p = dfsStack.top().first;
        auto side = dfsStack.top().second;
        dfsStack.pop();
        for(int i = 0; i < 4; i++)
        {
            auto d = dir[i];
            point pd = { p.x+d.x, p.y+d.y };
            if(valid(p.x, p.y, pd.x, pd.y))
            {
                auto newside = flip(side, i);
                if(A[newside][pd.x][pd.y] > A[side][p.x][p.y])
                {
                    A[newside][pd.x][pd.y] = A[side][p.x][p.y] + 1;
                    dfsStack.push( { { pd.x, pd.y }, newside } );
                }
            }
        }
    }
    unsigned int mmin = 999999999;
    for(int i = 0; i < 4; i++)
    {
        mmin = min(mmin, A[160 + i][c][d]);
    }
    if(mmin == 999999999)
        cout << "No solution";
    else
        cout << mmin;
}