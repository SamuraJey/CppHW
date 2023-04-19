#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int penalty = 0;
    while (a.size() > 2) {
        int min_penalty = a[1] * (a[0] + a[2]); // штраф для первого числа
        int min_index = 1; // индекс числа, которое нужно удалить
        for (int i = 2; i < a.size() - 1; i++) {
            int p = a[i] * (a[i-1] + a[i+1]); // штраф для текущего числа
            if (p < min_penalty) {
                min_penalty = p;
                min_index = i;
            }
        }
        penalty += min_penalty;
        a.erase(a.begin() + min_index); // удаление числа
    }

    cout << (penalty + a[0] * a[1]) - 2 << endl;
    return 0;
}
