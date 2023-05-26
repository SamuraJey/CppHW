#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Структура для хранения точки на изображении
struct Point {
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
    // need to compare equality of it operator == must be overloaded

    // Перегрузка оператора сравнения для точек
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

};

// Функция для поворота точки на 90 градусов по часовой стрелке
Point rotate90(const Point& p, int n, int m) {
    return Point(p.y, n - 1 - p.x);
}

// Функция для поворота точки на 180 градусов по часовой стрелке
Point rotate180(const Point& p, int n, int m) {
    return Point(m - 1 - p.x, n - 1 - p.y);
}

// Функция для поворота точки на 270 градусов по часовой стрелке
Point rotate270(const Point& p, int n, int m) {
    return Point(m - 1 - p.y, p.x);
}

// Функция для отражения точки относительно вертикальной оси
Point reflect(const Point& p, int n, int m) {
    return Point(m - 1 - p.x, p.y);
}

// Функция для преобразования изображения в набор точек
vector<Point> imageToPoints(const vector<string>& image) {
    vector<Point> points;
    int n= image.size();
    int m = image[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (image[i][j] == '#') {
                points.push_back(Point(i, j));
            }
        }
    }
    return points;
}

// Функция для построения всех возможных соответствий между точками на двух изображениях
set<pair<Point, Point>> buildCorrespondences(const vector<Point>& points1, const vector<Point>& points2,
    Point (*transform)(const Point&, int, int)) {
    set<pair<Point, Point>> correspondences;
    for (const auto& p1 : points1) {
        for (const auto& p2 : points2) {
            if (transform(p1, 500, 500) == p2) {
                correspondences.insert(make_pair(p1, p2));
            }
        }
    }
    return correspondences;
}

// Функция для проверки, совпадают ли множества соответствий для двух изображений
bool areCorrespondencesEqual(const vector<Point>& points1, const vector<Point>& points2) {
    set<pair<Point, Point>> correspondences1 = buildCorrespondences(points1, points2, rotate90);
    set<pair<Point, Point>> correspondences2 = buildCorrespondences(points1, points2, rotate180);
    set<pair<Point, Point>> correspondences3 = buildCorrespondences(points1, points2, rotate270);
    set<pair<Point, Point>> correspondences4 = buildCorrespondences(points1, points2, reflect);
    return correspondences1 == correspondences2 && correspondences2 == correspondences3 && correspondences3 == correspondences4;
}

int main() {
    // Считываем входные данные
    int n, m;
    vector<string> image1, image2;
    ifstream fin("INPUT.TXT");
    fin >> n >> m;
    image1.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> image1[i];
    }
    image2.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> image2[i];
    }
    fin.close();

    // Преобразуем изображения в наборы точек
    vector<Point> points1 = imageToPoints(image1);
    vector<Point> points2 = imageToPoints(image2);

    // Проверяем, одинаковы ли изображения
    bool areEqual = areCorrespondencesEqual(points1, points2);

    // Выводим результат в файл OUTPUT.TXT
    ofstream fout("OUTPUT.TXT");
    if (areEqual) {
        fout << "Yes" << endl;
    } else {
        fout << "No" << endl;
    }
    fout.close();

    return 0;
}