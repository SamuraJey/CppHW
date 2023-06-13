#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Point
{
    long x;
    long y;
};

void readCoordinates(int numPoints, vector<Point> &points)
{
    for (int i = 0; i < numPoints; i++)
    {
        long x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
}

Point calculations(int n, vector<Point> &points)
{
    long totalArea = 0;
    long pointsOnBoundary = 0;
    int innerPoint = 2;
    for (int i = 0; i < n; i++)
    {
        Point currentPoint = points[i];
        Point nextPoint = points[(i + 1) % n];
        totalArea += (currentPoint.x * nextPoint.y) - (currentPoint.y * nextPoint.x);
        long edgeX = nextPoint.x - currentPoint.x;
        long edgeY = nextPoint.y - currentPoint.y;
        long gcdValue = gcd(edgeX, edgeY);
        pointsOnBoundary += abs(gcdValue);
    }

    long area = abs(totalArea) - pointsOnBoundary + innerPoint;
    long latticePoints = area / 2;
    Point answ = {latticePoints, pointsOnBoundary};
    return answ;
}

int main()
{
    int numPoints;
    cin >> numPoints;
    vector<Point> points(numPoints);
    readCoordinates(numPoints, points);
    Point answer = calculations(numPoints, points);
    cout << answer.x << " " << answer.y << endl;
    return 0;
}
