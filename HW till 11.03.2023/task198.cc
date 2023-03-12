#include <iostream>
#include <vector>

using namespace std;

int main()
{
int size_matrix, size_equation;
// Чтение размерности матрицы и системы уравнений
cin >> size_matrix;
size_equation = size_matrix + 1;

// Инициализация матрицы коэффициентов и свободных членов
vector<vector<double>> matrix(size_matrix, vector<double>(size_equation));

// Чтение матрицы коэффициентов и свободных членов
for (int row = 0; row < size_matrix; row++) {
    for (int col = 0; col < size_equation; col++) {
        cin >> matrix[row][col];
    }
}

// Приведение матрицы к треугольному виду
for (int i = 0; i < size_matrix; i++) {
    double pivot = matrix[i][i];
    for (int j = size_matrix; j >= i; j--) {
        matrix[i][j] /= pivot;
    }
    for (int j = i + 1; j < size_matrix; j++) {
        double coefficient = matrix[j][i];
        for (int k = size_matrix; k >= i; k--) {
            matrix[j][k] -= coefficient * matrix[i][k];
        }
    }
}

// Решение системы уравнений методом обратного хода
vector<double> solution(size_matrix);
solution[size_matrix - 1] = matrix[size_matrix - 1][size_matrix];
for (int i = size_matrix - 2; i >= 0; i--) {
    solution[i] = matrix[i][size_matrix];
    for (int j = i + 1; j < size_matrix; j++) {
        solution[i] -= matrix[i][j] * solution[j];
    }
}

// Вывод решения системы уравнений
for (int i = 0; i < size_matrix; i++) {
    cout << solution[i] << " ";
}
cout << endl;

return 0;
}