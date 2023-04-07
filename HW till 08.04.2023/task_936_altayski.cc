#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y, n;
    double r;
    cin >> x >> y >> r >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;

        double distance = sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi));
        if (distance <= r && abs(xi - x) <= sqrt(r * r - (y - yi) * (y - yi))) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
