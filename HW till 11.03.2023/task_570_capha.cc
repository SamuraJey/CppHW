#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 
    int minx{ 1001 }, maxx{ -1 }, miny{ 1000 }, maxy{ -1 };
    vector <string> p(n);
    getline(cin, p[0]); // готовим буфер для чтения
    for (int z = 0; z < n; z++) { // вводим строки поля
            getline(cin, p[z]);
            if (p[z].find('*') == std::string::npos) continue; // звезда не найдена
            int k = p[z].find('*'); // ищем слева
            if (k < minx) minx = k; // новая минимальная граница слева
            k = p[z].rfind('*');    // ищем справа
            if (k > maxx) maxx = k; // новая максимальная граница справа
            if (z < miny) miny = z; // новая минимальная граница сверху
            if (z > maxy) maxy = z; // новая граница снизу
    }
    if (minx == 1001) { cout << "CIRCLE"; return 0; } // ни одной звездочки не было
    
    // проверяем границу
    for (int sminx = minx - 1; sminx <= minx + 1; sminx++) {
        for (int sminy = miny - 1; sminy <= miny + 1; sminy++) {
            for (int smaxx = maxx - 1; smaxx <= maxx + 1; smaxx++) {
                    for (int smaxy = maxy - 1; smaxy <= maxy + 1; smaxy++) {
                        if (smaxx - sminx == smaxy - sminy && // квадрат ли это и лежит ли он в границах поля
                            smaxx - sminx >= 2 && sminx >= 0 && smaxx <= m &&
                            sminy >= 0 && smaxy <= n) {
                            for (int z = minx + 2; z < maxx - 1; z++) {
                                    for (int x = miny + 2; x < maxy - 1; x++) {
                                        if (p[x][z]!='*') { cout << "CIRCLE"; return 0; } // нашли в квадрате дырку
                                    }
                                }
                            cout << "SQUARE"; return 0; // это - квадрат
                            }
                    }
            }
        }
    }
    cout << "CIRCLE";
    return 0;
}