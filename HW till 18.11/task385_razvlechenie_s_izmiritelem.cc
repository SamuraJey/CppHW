#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{

    string filename = "input385.txt";
    string ofilename = "output385.txt";
    ifstream input(filename);

    if (!input)
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    ofstream output(ofilename);

    int n;
    input >> n;
    vector <double> x(n);
    vector <double> y(n);
    set <double> result;

    for (int i = 0; i < n; i++)
    {
        input >> x[i] >> y[i];
    }

    for(int j = 0; j < n; j++)
    {
        for (int k = j+1; k < n; k++)
        {
            result.insert(sqrt((x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k])));
        }
    }

    output << result.size() << endl;
    output << setprecision(10);
    for (auto answ : result)
    {
        output << answ << endl;
    }
    
    input.close();
    output.close();
    return 0;
}

/*
ЗАДАЧА №385 		
	
Развлечения с измерителем
(Время: 1 сек. Память: 16 Мб Сложность: 28%)

Дима обнаружил у папы на столе специальный чертежный прибор, похожий на циркуль-измеритель. Измеритель отличается от обычного циркуля тем, что в обеих его ножках находятся иголки (у обычного циркуля в одной ножке находится иголка, а в другой – грифель).

Кроме измерителя Дима нашел на столе клетчатый лист бумаги, в углах некоторых клеток которого были нарисованы точки. Так как измеритель служит для измерения расстояний, то Дима решил измерить все попарные расстояния между всеми точками на листе бумаги.

Ваша задача - написать программу, которая по координатам точек определит, сколько различных расстояний встречается среди расстояний, которые измерил Дима.
Входные данные

Первая строка входного файла INPUT.TXT содержит число n – количество точек (2 ≤ n ≤ 50). Следующие n строк содержат по два целых числа – координаты точек. Координаты не превышают 104 по абсолютной величине.
Выходные данные

На первой строке выходного файла OUTPUT.TXT выведите k – количество различных расстояний, которые измерил Дима. Следующие k строк должны содержать по одному вещественному числу – сами расстояния. Расстояния должны быть выведены в возрастающем порядке. Каждое число должно быть выведено с точностью не менее чем 10-9.
Пример
№	INPUT.TXT	OUTPUT.TXT
1	4
0 0
1 1
1 0
0 1 	2
1.0
1.414213562373
*/