#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_matrices, matrix_size, row_index, col_index, mod_value;
    cin >> num_matrices >> matrix_size >> row_index >> col_index >> mod_value;

    // инициализация начальной матрицы
    vector<vector<int>> current_matrix, result_matrix;
    for (int i = 0; i < matrix_size; ++i) 
    {
        vector<int> row(matrix_size);
        for (int j = 0; j < matrix_size; ++j)
        {
            cin >> row[j];
            row[j] %= mod_value;
        }
        current_matrix.push_back(row);
    }

    // умножение матриц
    result_matrix = current_matrix;
    for (int k = 1; k < num_matrices; ++k) 
    {
        vector<vector<int>> next_matrix;
        for (int i = 0; i < matrix_size; ++i) 
        {
            vector<int> row(matrix_size);
            for (int j = 0; j < matrix_size; ++j) 
            {
                cin >> row[j];
                row[j] %= mod_value;
            }
            next_matrix.push_back(row);
        }

        for (int i = 0; i < matrix_size; ++i) {
            for (int j = 0; j < matrix_size; ++j)
            {
                int sum = 0;
                for (int h = 0; h < matrix_size; ++h)
                    sum += current_matrix[i][h] * next_matrix[h][j];
                result_matrix[i][j] = sum % mod_value;
            }
        }
        current_matrix = result_matrix;
    }

    // вывод результата
    cout << result_matrix[row_index - 1][col_index - 1];
}
