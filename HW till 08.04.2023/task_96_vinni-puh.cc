#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, Y, X;
    cin >> N >> M >> Y >> X;

    int row = 1, col = 1;
    int dir = 1; // 1 - right, 2 - down, 3 - left, 4 - up
    int count = 0;

    while (!(row == Y && col == X && dir == 1))
    {
        count++;
        if (dir == 1) {
            col++;
            if (col > M) {
                dir = 2;
                col--;
            }
        } else if (dir == 2) {
            row++;
            if (row > N) {
                dir = 3;
                row--;
            }
        } else if (dir == 3) {
            col--;
            if (col < 1) {
                dir = 4;
                col++;
            }
        } else if (dir == 4) 
        {
            row--;
            if (row < 1) {
                dir = 1;
                row++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
