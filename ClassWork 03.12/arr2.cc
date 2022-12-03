#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int flag = 0;
    vector <int> first = {1, 2, 3, 3, 4, 4, 5, 5}; //массив 1
    vector <int> second = {3, 4, 4}; // массив 2

    vector <int> combine;
    multiset <int> intersec;
    multiset <int> difference;

    set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(intersec, intersec.end()));
    
    cout << "INTERSEC" << endl;
    for (auto i : intersec)
    {
        cout << i << " ";
    }
    
    combine = first;
    for (auto i : second)
    {
        combine.push_back(i);
    }
    cout << endl;

    sort(combine.begin(), combine.end());

    cout << "COMBINE" << endl;
    for (auto i : combine)
    {
        cout << i << " ";
    }
    cout << endl;

    set_difference(first.begin(), first.end(), second.begin(), second.end(), inserter(difference, difference.end()));

    cout << "DIFFERENCE" << endl;
    for (auto i : difference)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
task
https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_0df250b0-6288-4810-be5e-0512e39618e2
Arr2. Даны два неубывающих массива чисел. Сформировать неубывающие массивы, являющиеся объединением, пересечением и разностью этих двух массивов (разность в смысле мультимножеств).

Я понимаю слова "Сформировать неубывающие массивы", так что, в объединении массивов получается массив со всеми значениями исходных
соответсвенно при пересечении и разнице тоже возможны повторения элементов, так как мы делаем "массивы" а не множества

пояснение насчет мультимножеств
Арифметической разностью мультимножеств AM и BM называется мультимножество, состоящее из тех элементов мультимножества AM, кратность которых превышает кратность соответствующих элементов в мультимножестве BM. Кратность каждого элемента результирующего множества равна разности кратностей соответствующих элементов в вычитаемых мультимножествах:
CM= AM-BM= {kx | kx = kixi-kjxj, если ki>kj; 0, в противном случае}, kixiAM, kjxjBM.
*/