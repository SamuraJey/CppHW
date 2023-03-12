#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
//Sorry for this code...
int main()
{
    int numRows, numCols;
    int numCollumns = 0;
    int numWalls = 0;
    cin >> numRows >> numCols;

    vector<vector<int>> grid(numRows, vector<int>(numCols));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> grid[i][j];
        }
    }

    // Count the number of distinct colored quadrilaterals in the grid
    for (int i = 0; i < numRows - 1; i++) {
        for (int j = 0; j < numCols - 1; j++) {
            int currentColor = grid[i][j];
            if (currentColor != grid[i + 1][j] || currentColor != grid[i][j + 1] || currentColor != grid[i + 1][j + 1]) {
                numCollumns++;
            }
        }
    }

    // Count the number of vertical walls in the grid
    for (int i = 0; i < numRows - 1; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] != grid[i + 1][j]) {
                numWalls++;
            }
        }
    }

    // Count the number of horizontal walls in the grid
    for (int j = 0; j < numCols - 1; j++) {
        for (int i = 0; i < numRows; i++) {
            if (grid[i][j] != grid[i][j + 1]) {
                numWalls++;
            }
        }
    }

    // Calculate the final score based on the number of collumns and walls
    long double score = 0.2 * 0.2 * 3 * numCollumns + 0.2 * 0.8 * 3 * numWalls;
    cout << score << endl;

    return 0;
}
