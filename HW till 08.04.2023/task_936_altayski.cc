#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int max_visible_points(double x, double y, double r, vector<pair<double, double>>& points) {
    int max_count = 0;
    for (int i = 0; i < points.size(); i++) {
        double dist = sqrt(pow(points[i].first - x, 2) + pow(points[i].second - y, 2));
        if (dist <= r) {
            int count = 0;
            for (int j = 0; j < points.size(); j++) {
                if (j != i) {
                    double angle1 = atan2(points[j].second - y, points[j].first - x);
                    double angle2 = atan2(points[i].second - y, points[i].first - x);
                    double angle = angle1 - angle2;
                    if (angle < 0) angle += 2 * M_PI;
                    if (angle <= M_PI && dist >= sqrt(pow(points[j].first - x, 2) + pow(points[j].second - y, 2))) {
                        count++;
                    }
                }
            }
            if (count > max_count) {
                max_count = count;
            }
        }
    }
    return max_count + 1;
}

int main() 
{
    double x, y, r;
    int n;
    cin >> x >> y >> r >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    int max_points = max_visible_points(x, y, r, points);
    cout << max_points << endl;
    return 0;
}
