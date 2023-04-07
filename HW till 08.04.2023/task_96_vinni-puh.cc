#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiral_matrix(int m, int n) {
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    int count = 0;
    int i = 0, j = 0;
    int di = 0, dj = 1;

    for (int k = 0; k < m * n; k++) 
    {
        count++;
        matrix[i][j] = count;
        if (matrix[(i+di+m)%m][(j+dj+n)%n] != 0 || (i+di < 0 || i+di >= m || j+dj < 0 || j+dj >= n)) {
            int temp = di;
            di = dj;
            dj = -temp;
        }
        i += di;
        j += dj;
    }
    return matrix;
}

int main() {
    int m = 0, 
    n = 0;
    int x = 0;
    int y = 0;
    cin >> n >> m >> y >> x;
    vector<vector<int>> matrix = spiral_matrix(m, n);
    
    std::cout << matrix[y-1][x-1] << std::endl;

    //cout << "Number of cells visited: " << endl;
    return 0;
}
