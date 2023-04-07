#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, pair<int, int>>> scores(N); // вектор пар чисел
    for (int i = 0; i < N; i++)
    {
        int ai1, ai2, ai3;
        cin >> ai1 >> ai2 >> ai3;
        scores[i] = make_pair(ai1, make_pair(ai2, ai3)); // добавление пары чисел в вектор
    }

    // Инициализация множества различных итогов игры
    set<int> unique_results;

    // Перебор всех возможных значений числа p от 0 до 1 с шагом 0.01
    for (int p = 0; p <= 100; p++) {
        double p_value = p / 100.0;
        for (int i = 0; i < N; i++) {
            // Вычисление итогового количества очков Si
            int ai1 = scores[i].first;
            int ai2 = scores[i].second.first;
            int ai3 = scores[i].second.second;
            double Si = ai1 * pow(p_value, 2) + ai2 * p_value + ai3;
            int Mi = 0;
            for (int j = 0; j < N; j++) {
                if (i != j && Si < scores[j].first * pow(p_value, 2) + scores[j].second.first * p_value + scores[j].second.second) {
                    Mi++;
                }
            }
            // Добавление места Mi в множество различных итогов игры
            unique_results.insert(Mi + 1);
        }
    }

    // Вывод количества различных итогов игры
    cout << unique_results.size() << endl;

    return 0;
}
