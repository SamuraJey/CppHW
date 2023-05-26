#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


// Отражение матрицы по горизонтали
vector<vector<char>> mirrorMatrixHorizontally(vector<vector<char>> matrix)
{
    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();
    vector<vector<char>> result(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][cols - 1 - j] = matrix[i][j];
        }
    }

    return result;
}

// Поворот матрицы на 90 градусов против часовой стрелки
vector<vector<char>> rotateMatrixCounterClockwise(vector<vector<char>> matrix)
{
    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();
    vector<vector<char>> result(cols, vector<char>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[cols - 1 - j][i] = matrix[i][j];
        }
    }
    return result;
}

// Нахождение подматрицы, содержащей все символы '#'
vector<vector<char>> findSubmatrix(vector<vector<char>> matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int minRow = rows, maxRow = -1, minCol = cols, maxCol = -1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '#')
            {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    if (maxRow == -1)
    {
        return vector<vector<char>>();
    }

    vector<vector<char>> result(maxRow - minRow + 1, vector<char>(maxCol - minCol + 1));

    for (int i = minRow; i <= maxRow; i++)
    {
        for (int j = minCol; j <= maxCol; j++)
        {
            result[i - minRow][j - minCol] = matrix[i][j];
        }
    }

    return result;
}

// Ввод матрицы с клавиатуры
vector<vector<char>> inputMatrix()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> matrix(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

int main()
{
    // Находим подматрицы для сравнения
    vector<vector<char>> matrixA = findSubmatrix(inputMatrix());
    vector<vector<char>> matrixB = findSubmatrix(inputMatrix());

    // Проверяем отражения и повороты матрицы A
    for (int i = 0; i < 2; i++)
    {
        matrixA = mirrorMatrixHorizontally(matrixA);

        for (int j = 0; j < 4; j++)
        {
            matrixA = rotateMatrixCounterClockwise(matrixA);
            if (matrixA == matrixB)
            {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}