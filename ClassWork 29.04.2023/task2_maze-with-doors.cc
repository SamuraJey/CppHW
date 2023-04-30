/*
2 задача)Есть лабиринт в котором есть двери трех цветов: красный, зеленый и синий. 
По лабиринту раскиданы ключи: красные, зеленые и синие. 
Пройдя по ключу вы его подбираете. Через дверь можно проходить только имея ключ
того же цвета. Без ключа - нельзя. Нужно найти кратчайший путь от старта до финиша.

Входные данные:
на первой строке два числа, количество строк n и столбцов m в лабиринте
на второй строке два числа, координаты старта
на третьей строке два числа, координаты финиша
далее n строк по m символов, где # - стена, . - проходимая клетка, 
R - красный ключ, G - зеленый ключ, B - синий ключ,
r - красная дверь, g - зеленая дверь, b - синяя дверь

Выходные данные:
число - длина кратчайшего пути от старта до финиша, если пути нет, то -1

пример входных данных:
5 6
0 0
4 0
S.....
.##.RB
.G###g
#####r
F....b

*/


#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

const int MAXN = 800;
const int INF = 1e9;

// Да, глобальные переменные 
int n, m; // размер лабиринта
char maze[MAXN][MAXN]; // сам лабиринт
int dist[MAXN][MAXN][8]; // Такая запись объявляет трехмерный массив dist размера MAXN x MAXN x 8. 8 - это количество возможных комбинаций ключей. т.к. ключей 3, то комбинаций 2^3 = 8
int startX, startY, endX, endY; // координаты начала и конца

struct node // структура для хранения состояния в очереди
{
    int x;
    int y;
    int keys;
};

bool isValid(int x, int y) // проверка, является ли данная точка допустимой позицией в лабиринте
{
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#';
}

int findShortestPath() // поиск кратчайшего пути в лабиринте обходом в ширину
{
    memset(dist, -1, sizeof(dist)); // заполняем массив расстояний значением -1
    queue<node> bfsQueue; // очередь для обхода в ширину
    bfsQueue.push({startX, startY, 0}); // добавляем в очередь начальное состояние
    dist[startX][startY][0] = 0; // расстояние до начального состояния равно 0
    int diffX[] = {0, 0, 1, -1}; // смещения для обхода в ширину
    int diffY[] = {1, -1, 0, 0}; 

    while (!bfsQueue.empty())  // пока очередь не пуста
    {
        int x = bfsQueue.front().x; // извлекаем состояние из очереди
        int y = bfsQueue.front().y;
        int keys = bfsQueue.front().keys;
        bfsQueue.pop();
        if (x == endX && y == endY && keys == 7)  // если мы достигли конца, то возвращаем расстояние до него
        {
            return dist[x][y][keys];
        }
        for (int i = 0; i < 4; i++)  // добавляем в очередь все соседние состояния
        {
            int nextX = x + diffX[i]; // смещаемся в соседнюю клетку
            int nextY = y + diffY[i];
            if (isValid(nextX, nextY)) 
            {
                int nkeys = keys; // обновляем ключи
                if (maze[nextX][nextY] == 'R') nkeys |= 1; // если мы нашли ключ, то добавляем его в ключи методом побитового ИЛИ
                if (maze[nextX][nextY] == 'G') nkeys |= 2;
                if (maze[nextX][nextY] == 'B') nkeys |= 4;
                if (dist[nextX][nextY][nkeys] == -1)  // если мы еще не были в данном состоянии, то добавляем его в очередь
                {
                    if ((maze[nextX][nextY] >= 'a' && maze[nextX][nextY] <= 'c') && !(nkeys & (1 << (maze[nextX][nextY] - 'a')))) // если мы не можем открыть дверь, то пропускаем данное состояние
                    {
                        continue;
                    }
                    bfsQueue.push({nextX, nextY, nkeys}); // добавляем состояние в очередь
                    dist[nextX][nextY][nkeys] = dist[x][y][keys] + 1; // обновляем расстояние до данного состояния
                }
            }
        }
    }
    return -1; // если мы не смогли достичь конца, то возвращаем -1
}

int main() {

    ifstream inputFile("maze-w-doors.txt"); // открываем файлы для чтения и записи
    ofstream outputFile("maze-w-doors-out.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Ошибка при открытии файла" << endl;
        return 1;
    }
    if (!outputFile.is_open()) 
    {
        cerr << "Ошибка при записи файла" << endl;
        return 1;
    }

    inputFile >> n >> m;
    inputFile >> startX >> startY >> endX >> endY;

    for (int i = 0; i < n; i++) // считываем лабиринт
    {
        for (int j = 0; j < m; j++) 
        {
            inputFile >> maze[i][j];
        }
    }
    
    int answ = findShortestPath(); // ищем кратчайший путь
    if (answ != -1)
    {    
        outputFile << answ << endl; // выводим ответ
    }
    else
    {
        outputFile << "No solution" << endl; // если пути нет, то выводим "No solution"
    }

    inputFile.close();
    outputFile.close();

    return 0;
}