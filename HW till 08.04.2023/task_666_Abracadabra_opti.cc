#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int n = 0;
    cin >> n;
    string sequence = "a"; // начальная строка
    for (int i = 1; i <= 25; i++) // проходим по всем буквам алфавита (от b до z)
    {
        sequence = char('a' + i) + sequence + sequence; // добавляем новую букву слева и удваиваем строку
    }
    int len = sequence.length();
    while (len < n)
    {
        n -= len;
        len /= 2;
    }
    cout << sequence[n - 1] << endl;
    return 0;
}
