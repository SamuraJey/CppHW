#include <iostream>
#include <string>
#include <fstream>
#include "vector"

using namespace std;


int main()
{

    string filename = "input600.txt";
    string ofilename = "output600.txt";
    ifstream input(filename);

    if (!input)
    {
        std::cout << "Error opening file" << std::endl;
        return 0;
    }
    ofstream output(ofilename);

    int n;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    input >> n;
    vector <string> arr(n);

    for (int i = 0; i < n; i++) 
    {
        input >> arr[i];
    }

    for (auto mystr : arr)
    {
        if (mystr.size() % 3 != 0) {
            output << "NO" << endl;
            continue;
        }
        for (int k = 0; k < mystr.size() - 1; k++)
        {
            int dk = int(mystr[k]);
            int kk = int(mystr[k+1]);


            if (int(mystr[k]) > (mystr[k + 1])) 
            {
                output << "NO" << endl;
                continue;
            }
        }
        for (int num : mystr) 
        {
            switch (num)
            {
            case 48:
                counter1++;
                break;
            case 49:
                counter2++;
                break;
            case 50:
                counter3++;
                break;

            default:
                break;
            }
        }
        if (counter1 == counter2 || counter1 == counter3 || counter2 == counter3) 
        {
            output << "YES" << endl;
        }
        else 
        {
            output << "NO" << endl;
            continue;
        }
    }
    
    input.close();
    output.close();
    return 0;
}


/*
ЗАДАЧА №600 		
	
Распознавание языка
(Время: 1 сек. Память: 16 Мб Сложность: 28%)

Важным понятием теории формальных грамматик и автоматов является формальный язык. Неформально его можно определить как некоторое множество слов, где под словом понимается некоторая строка из символов.

В этой задаче необходимо проверить, принадлежит ли данное слово языку {0n1n2n, n ≥ 1}. В этот язык входят те и только те слова, которые имеют такую структуру: в них нулей столько же, сколько единиц, а единиц - столько же, сколько и двоек. При этом любой ноль находится ближе к началу слова, чем любая единица, а любая единица находится ближе к началу слова, чем любая двойка. Например, слово 001122 принадлежит этому языку, а слово 0000111122220 - не принадлежит.
Входные данные

Первая строка входного файла INPUT.TXT содержит целое положительное число n (n ≤ 10) – количество слов, которые надо проанализировать. Далее идут n строк, каждая из которых содержит по одному слову. Слова имеют длину не более тридцати тысяч символов и состоят только из нулей, единиц и двоек. Каждое из слов состоит хотя бы из одного символа.
Выходные данные

Выходной файл OUTPUT.TXT должен содержать ровно n строк. Для каждого слова из входного файла выведите по одной строке, содержащей слово YES, если оно принадлежит указанному выше языку, и NO - иначе.
Примеры
№	INPUT.TXT	OUTPUT.TXT
1	3
001122
00011122222
000111222	YES
NO
YES
2	2
0000111122220
012	NO
YES
*/