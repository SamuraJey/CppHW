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
Так же проход по порталу стоит 1 шага. Т.е. если мы встали на 12, то переход в другую 12 стоит 1 шаг.

*/



#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <utility>

using namespace std;

struct Point 
{
    int row;
    int col;
};

int teleportCount = 0;

// Проверка, является ли данная точка допустимой позицией в лабиринте
bool isValid(int row, int col, int numRows, int numCols) {
    return (row >= 0) && (row < numRows) && (col >= 0) && (col < numCols);
}

// Проверка, является ли данная точка проходимой (не стеной)
bool isPassable(const vector<vector<int>>& maze, int row, int col) {
    return maze[row][col] != 1;
}

// Поиск кратчайшего пути в лабиринте с телепортами с помощью алгоритма BFS
int findShortestPath(const vector<vector<int>>& maze, Point start, Point end) {
    const int numRows = maze.size();
    const int numCols = maze[0].size();
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
    vector<vector<Point>> parent(numRows, vector<Point>(numCols, { -1, -1 }));

    // Перемещения вокруг текущей точки
    const int dx[] = { -1, 0, 1, 0 };
    const int dy[] = { 0, 1, 0, -1 };

    queue<Point> q;
    q.push(start);
    visited[start.row][start.col] = true;

    int endCellValue = maze[end.row][end.col];  // Значение конечного телепорта


    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        // Если достигли конечной точки, возвращаем длину пути
        if (current.row == end.row && current.col == end.col) {
            int length = 0;
            while (current.row != start.row || current.col != start.col) {
                length++;
                current = parent[current.row][current.col];
            }
            return length;
        }

        // Перебираем все соседние точки
        for (int i = 0; i < 4; i++) 
        {
            int newRow = current.row + dx[i];
            int newCol = current.col + dy[i];

            // Если соседняя точка допустима и не посещена
            if (isValid(newRow, newCol, numRows, numCols) && isPassable(maze, newRow, newCol) && !visited[newRow][newCol]) {
                q.push({ newRow, newCol });
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
                q.push({ teleportCoord.first, teleportCoord.second });
                visited[teleportCoord.first][teleportCoord.second] = true;
                parent[teleportCoord.first][teleportCoord.second] = current;
            }
        }
    }
    // Если путь не найден
    return -1;
}

int main() {
    // Открываем входной файл
    ifstream input("maze.txt");
    if (!input) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

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


    // Вызываем функцию поиска кратчайшего пути
    int shortestPathLength = findShortestPath(maze, start, end);

    // Выводим результат
    if (shortestPathLength != -1) {
        cout << "Кратчайший путь: " << shortestPathLength << endl;
    } else {
        cout << "Путь не найден." << endl;
    }

    return 0;
}

