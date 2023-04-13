#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для проверки, является ли последовательность кодом Грея
bool isGreyCode(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int diff = a[i] ^ a[(i + 1) % n]; // XOR двух соседних элементов
        if ((diff & (diff - 1)) != 0) { // Если различий в бинарной записи больше чем 1
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(1 << n); // Создаем вектор a длиной 2^n
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        swap(a[x], a[y]); // Меняем местами элементы с индексами x и y
        if (isGreyCode(a)) { // Проверяем, является ли после перестановки последовательность кодом Грея
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
