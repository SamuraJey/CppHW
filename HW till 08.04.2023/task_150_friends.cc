#include <iostream>
#include <vector>

using namespace std;

// Функция для поиска в глубину (DFS)
// принимает матрицу смежности adjMatrix по ссылке, булевый массив в котром хранится посещенна ли вершина
// потом начальную вершину (не по ссылке) и потом счетчик по ссылке
void dfs(vector<vector<int>>& adjMatrix, vector<bool>& visited, int peak, int& count)
{
    visited[peak] = true;
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[peak][i] == 1 && !visited[i])
        {
            count++; // увеличиваем счетчик друзей, если дружба гарантированна
            dfs(adjMatrix, visited, i, count);
        }
    }
}

int main()
{
    int N, S;
    cin >> N >> S;

    vector<vector<int>> adjMatrix(N, vector<int>(N, 0)); // вводим с клавиатуры матрицу смежности
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    S--; // уменьшаем номер S на 1, так как входая индексация начинается с 1

    vector<bool> visited(N, false); // массив посещенных вершин
    int count = 0; // счетчик друзей
    dfs(adjMatrix, visited, S, count); // вызываем DFS
    cout << count << endl; // выводим количество гарантированных друзей у человека S
    return 0;
}
