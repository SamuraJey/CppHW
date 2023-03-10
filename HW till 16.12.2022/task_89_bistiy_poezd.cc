#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    vector <string> name(n);
    vector <string> time1(n);
    vector <string> time2(n);
    vector <double> time(n);
    for (int z = 0; z < n; z++)
    {
            getline(cin, name[z]);
            // удаляем концевые пробелы
            while (name[z][name[z].length() - 1] == ' ')
            {
                int k = name[z].length();
                name[z] = name[z].substr(0, k - 1);
            }
            // удаляем ведущие пробелы
            while (name[z][0] != '"')
            {
                int k = name[z].length();
                name[z] = name[z].substr(1, k-1);
            }
            // выделяем время прибытия
            int k = name[z].length();
            time2[z]= name[z].substr(k-5, 5);
            // выделяем время отбытия
            time1[z] = name[z].substr(k - 11, 5);
            // выделяем название поезда
            name[z] = name[z].substr(0, k - 12);
            // считаем время движения в минутах
            time[z] = ((time2[z][0] - '0') * 10 + time2[z][1] - '0') * 60.0 + ((time2[z][3] - '0') * 10 + (time2[z][4]) - '0');
            time[z] = time[z]-(((time1[z][0] - '0') * 10 + time1[z][1] - '0') * 60.0 + ((time1[z][3] - '0') * 10 + (time1[z][4]) - '0'));
            if (time[z] <= 0) time[z] += 24 * 60.0;
    }
    int min = time[0];
    int nmin = 0;
    if (n > 1)
    {
        for (int z = 1; z < n; z++)
        {
            if (min > time[z])
            {
                min = time[z];
                nmin = z;
            }   
        }
    }
    cout << "The fastest train is " << name[nmin] << "." << endl;
    cout << "Its speed is " << (int)(650.0 * 60.0 / time[nmin] + 0.5) << " km/h, approximately." << endl;
    return 0;
}