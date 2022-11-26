/*
Loops4. В массиве чисел найдите самый длинный подмассив из одинаковых чисел.
*/

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{



    vector <int> arr1(10000);
    srand (time(NULL));  //генерирование случайного числа
    int num;
    //Цикл выполняемый arr1.size раз,добавляет столько же случайных чисел
    // в массив(каждый раз генерируя новое rand()%10 от 0 до 10)
    for(int i = 0; i < arr1.size(); i++)
    {
        num = rand() % 10 + 1; // случайные числа от 0 до 20
        arr1[i] = num;
    }

    //for (auto i : Arr)
    //{
    //    cout << i << endl;
    //}
    

    //return 0;


    //int arr1[]{1, 1, 2, 1, 2, 2, 2, 1, 2, 3, 3};
    vector <int> arr2;
    vector <int> arr3(1);
    int counter = 0;
    //int count = size(a);
    //cout << count << endl;
    //int count = size(arr2);
    for (int i = 0; i < size(arr1) - 1; i++)
    {
        int hei = arr1[i];
        int hei2 = arr1[i+1];
        //arr2.push_back(arr1[i]);
        if (arr1[i] == arr1[i + 1])
        {
            arr2.push_back(arr1[i]);
            counter = size(arr2);
        }
        else
        {
            arr2.push_back(arr1[i]);
            if (counter > size(arr3) - 1)
            {
                arr3.clear();
                //arr3.insert(arr3.begin(), arr2.begin(), arr2.end());
                arr3 = arr2;
            }
            arr2.clear();
            counter = 0;
        }
    }

    if (size(arr3)-1 == 0)
    {
        arr3 = arr2;
    }
    for (auto i : arr3)
    {
        cout << i << ' ';
    }
    return 0;
}
