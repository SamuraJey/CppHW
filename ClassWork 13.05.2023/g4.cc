#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_divisible(string num, int divisor) {
    int remainder = 0;
    for (int i = 0; i < num.size(); i++) {
        remainder = remainder * 10 + (num[i] - '0');
        remainder %= divisor;
    }
    return remainder == 0;
}

string find_number(int n) {
    string num = "2";
    for (int i = 1; i < n; i++) {
        string num1 = "1" + num;
        string num2 = "2" + num;
        if (is_divisible(num1, pow(2, i+1))) {
            num = num1;
        } else {
            num = num2;
        }
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    string num = find_number(n);
    cout << num << endl;
    return 0;
}