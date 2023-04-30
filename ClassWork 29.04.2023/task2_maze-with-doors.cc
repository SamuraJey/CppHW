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
int dist[MAXN][MAXN][1 << 3]; // массив расстояний
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
    
    outputFile << findShortestPath() << endl; // выводим ответ

    inputFile.close();
    outputFile.close();

    return 0;
}