#include <iostream>

using namespace std;

// Оказывается сайт работает и со стандартными cin и cout, а файлы подключать не обязательно... мда.

int main(int argc, char const *argv[])
{
    unsigned long long N, K;
    cin >> N >> K;
    unsigned long long answ = N * (1 + K) * K / 2 - (K + 1) * (K - 1);
    cout << answ;

    return 0;
}
