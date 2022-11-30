#include <iostream>
#include <string>

using namespace std;

int main()
{
    int boys, girls;
    string s = "";
    cin >> boys >> girls;

    while (boys > 0 || girls > 0) //оптимальная рассадка получается BGG поэтому стараемся следовать ей
    {
        if (boys > 0)
        {
            s = s + 'B';
            boys--;
        }
        if (girls > 0)
        {
            s = s + 'G';
            girls--;
        }
        if (girls > 0)
        {
            s = s + 'G';
            girls--;
        }
    }
    cout << s;
    return 0;
}