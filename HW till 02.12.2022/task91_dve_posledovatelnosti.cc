#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a = { 0,2,3,4,7,13 };      // множество А
    vector <int> b = { 0,1,5,6,8,9,10,11,12 };     // множество В
    int an = 6;  // количество элементов множества А
    int bn = 9;  // количество элементов множества В
    while (n > an - 1 || n > bn - 1) // пока не доберемся до нужных номеров
    {    
        a.push_back(b[an - 1] + b[an - 3]);     // добавляем в А очередной элемент
        for (int z = a[an-1] + 1; z < a[an]; z++)
        { // в  В – пропущенные числа
            b.push_back(z); bn++; // растет и богатеет множество В
        }
        an++; // увеличиваем счетчик
    }

    cout << a[n] << endl << b[n];
    return 0;
}