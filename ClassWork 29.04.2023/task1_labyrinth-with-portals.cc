/*
Постановка задачи:
Дан лабиринт с телепортами и стенами. Найти кратчайший путь из точки A в точку B.
Входные данные:
В первой строке файла находятся размеры лабиринта (N и M). Во второй строке находятся координаты точки A, в третьей строке – координаты точки B. 
В следующих N строках находится описание лабиринта. 0 – проходимая клетка, 1 – стена, 2, 3, 4, … – телепорты. 
Гарантируется, что в если в лабиринте есть телепорт то он корректно задан.

Формат телепортов: числа больше 1 означает точку телепорта, например в входных данных
5 5 0 0 4 4
0 12 0 0 0
0 0 0 14 0
0 14 0 0 0
0 0 0 0 0
0 12 0 1 0

12 и 12, 14 и 14, 16 и 16 это точки телепорта. Из 12 можно попасть только в 12, из 14 только в 14, из 16 только в 16.

Считается, что вход и выход не могут быть в стене или на телепорте.

Так как по условию при выходе из телепорта мы беслпатно оказываемся в соседней клетке то пройденный путь и его длина не совпадают.
и вывод 
"Путь до конечной точки: (0, 0) (0, 1) (4, 0) (4, 1) (4, 2) (3, 4) 
Кратчайший путь: 4"
Правильный, так как в точке 0,1 мы попали в телепорт на точке (4, 0) и вышли из него в точке (4, 1), то же самое в точке (4, 2), там мы выходим в точке (3, 4) и бесплатно шагаем на точку выхода.
*/



#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <utility>
#include <algorithm>


using namespace std;

struct Point 
{
    int row;
    int col;
};

struct PathPoint
{
    int row;
    int col;
    int teleportCount;
};

int teleportCount = 0;
vector<PathPoint> path;

// Проверка, является ли данная точка допустимой позицией в лабиринте
bool isValid(int row, int col, int numRows, int numCols) 
{
    return (row >= 0) && (row < numRows) && (col >= 0) && (col < numCols);
}

// Проверка, является ли данная точка проходимой (не стеной)
bool isPassable(const vector<vector<int>>& maze, int row, int col) 
{
    return maze[row][col] != 1;
}

// Поиск кратчайшего пути в лабиринте с телепортами с помощью алгоритма BFS
void findShortestPath(const vector<vector<int>>& maze, Point start, Point end) 
{
    const int numRows = maze.size();
    const int numCols = maze[0].size();
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
    vector<vector<Point>> parent(numRows, vector<Point>(numCols, { -1, -1 }));

    // Перемещения вокруг текущей точки
    const int diffX[] = { -1, 0, 1, 0 };
    const int diffY[] = { 0, 1, 0, -1 };

    queue<Point> bfsQueue;
    bfsQueue.push(start);
    visited[start.row][start.col] = true;

    int endCellValue = maze[end.row][end.col];  // Значение конечного телепорта

    while (!bfsQueue.empty()) {
        Point current = bfsQueue.front();
        bfsQueue.pop();
        // Если достигли конечной точки, возвращаем длину пути
        if (current.row == end.row && current.col == end.col) 
        {
            int length = 0;
            while (current.row != start.row || current.col != start.col) 
            {
                length++;
                current = parent[current.row][current.col];
                PathPoint point;
                point.row = current.row;
                point.col = current.col;
                point.teleportCount = teleportCount;
                path.push_back(point);
            }
            reverse(path.begin(), path.end());
            return;
        }
        // Перебираем все соседние точки
        for (int i = 0; i < 4; i++) 
        {
            int newRow = current.row + diffX[i];
            int newCol = current.col + diffY[i];
            // Если соседняя точка допустима и не посещена
            if (isValid(newRow, newCol, numRows, numCols) && isPassable(maze, newRow, newCol) && !visited[newRow][newCol]) {
                bfsQueue.push({ newRow, newCol });
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = current;
            }
        }
        // Проверяем, является ли текущая точка телепортом
        int currentCellValue = maze[current.row][current.col];
        if (currentCellValue > 1 && currentCellValue != endCellValue) 
        {
            teleportCount++;
            // Находим координаты второго телепорта
            pair<int, int> teleportCoord;
            bool found = false;
            for (int row = 0; row < numRows; row++) 
            {
                for (int col = 0; col < numCols; col++) 
                {
                    if (maze[row][col] == currentCellValue && (row != current.row || col != current.col)) 
                    {
                        teleportCoord = make_pair(row, col);
                        found = true;
                        break;
                    }
                }
                if (found) 
                {
                    break;
                }
            }

            // Проверяем, является ли второй телепорт посещенным
            if (!visited[teleportCoord.first][teleportCoord.second]) 
            {
                bfsQueue.push({ teleportCoord.first, teleportCoord.second });
                visited[teleportCoord.first][teleportCoord.second] = true;
                parent[teleportCoord.first][teleportCoord.second] = current;
            }
        }
    }
    // Если путь не найден
    return;
}

int main() {
    // Открываем входной файл
    ifstream input("maze.txt");
    if (!input.is_open()) 
    {
        cerr << "Ошибка при открытии файла" << endl;
        return 1;
    }

    int offSet = 0;
    int numRows, numCols, startX, startY, endX, endY;
    input >> numRows >> numCols >> startX >> startY >> endX >> endY;

    // Чтение лабиринта из файла
    vector<vector<int>> maze(numRows, vector<int>(numCols));
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) 
        {
            input >> maze[row][col];
        }
    }

    // Находим координаты стартовой и конечной точек
    Point start, end;
    start.row = startX;
    start.col = startY;
    end.row = endX;
    end.col = endY;

    findShortestPath(maze, start, end);

    ofstream output("maze-out.txt");
    if (!output.is_open()) 
    {
        cerr << "Ошибка при записи файла" << endl;
        return 1;
    }

    // Выводим результат
    if (path.size() != 0) 
    {
        output << "Путь до конечной точки: ";
        for (size_t i = 0; i < path.size() - 1; ++i) 
        {
            const auto& point1 = path[i];
            const auto& point2 = path[i + 1];
            output << "(" << point1.row << ", " << point1.col << ") ";
            // Проверить разницу между point1 и point2 по строкам и столбцам
            if (abs(point1.row - point2.row) > 1 || abs(point1.col - point2.col) > 1) 
            {
                offSet++;
            }
        }
        output << "(" << path.back().row << ", " << path.back().col << ") " << endl;
        output << "Кратчайший путь: " << path.size() - offSet << endl;
    } 
    else 
    {
        output << "Путь не найден." << endl;
    }
    cout << path.size() << endl;

    input.close();
    output.close();
    return 0;
}

