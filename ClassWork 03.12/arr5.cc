#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int i, k;
    vector <int> a = {1, 2, 3, 6};

    for(i = k = 0; i < a.size(); i++)
    {
        if (k + 1 < a[i])
        {
        break;
        }
        k += a[i];
    }

    printf("Подходящее число = %d\n", k+1);

    return 0;
}

/*
Arr5. * Дан неубывающий массив положительных целых чисел.
Найти наименьшее положительное целое число, не представимое
в виде суммы элементов этого массива 
(каждый элемент разрешается использовать в сумме только один раз).

https://ulearn.me/course/basicprogramming/Zadachi_na_seminar_0df250b0-6288-4810-be5e-0512e39618e2
благослави господь тех кто придумывал задания на юлерн
*/
