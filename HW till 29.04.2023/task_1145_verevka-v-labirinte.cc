#include <iostream>

using namespace std;

unsigned char grid[820][821];
int maxDistance, maxI, maxJ, rows, columns;
int visited;

inline bool isValid(short x, short y)
{
    return x >= 0 && x < columns && y >= 0 && y < rows && (grid[x][y] & 127) == '.';
}

void dfs(short x, short y, int distance)
{
    if (!isValid(x, y) || ((grid[x][y] >> 7) != visited))
    {
        return;
    }
    grid[x][y] = (grid[x][y] & 127) | (~visited << 7);
    if (distance > maxDistance)
    {
        maxDistance = distance;
        maxI = x;
        maxJ = y;
    }
    dfs(x - 1, y, ++distance);
    dfs(x + 1, y, distance);
    dfs(x, y - 1, distance);
    dfs(x, y + 1, distance);
}

int main()
{
    cin >> rows >> columns;
    for (int i = 0; i < columns; i++)
    {
        cin >> grid[i];
    }

    int startI = -1, startJ = 0;
    for (int i = 0; i < columns && startI < 0; i++)
    {
        for (int j = 0; j < rows && startI < 0; j++)
        {
            if (grid[i][j] == '.')
            {
                startI = i;
                startJ = j;
            }
        }
    }

    dfs(startI, startJ, 0);
    visited = 1;
    dfs(maxI, maxJ, 0);
    cout << maxDistance << endl;
    return 0;
}
