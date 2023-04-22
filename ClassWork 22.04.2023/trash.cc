#include <bits/stdc++.h>

using namespace std;

int get_parent(int idx, vector<int> &parent) // Функция поиска родителя
{
    if (idx == parent[idx]) // Если индекс равен родителю, то возвращаем индекс
    {
        return idx;
    }
    return parent[idx] = get_parent(parent[idx], parent); // Иначе возвращаем родителя родителя рекурсивно идя до корня
}

void merge_set(int a, int b, vector<int> &parent, vector<int> &rnk) // Функция объединения двух множеств
{
    a = get_parent(a, parent); // Находим родителей
    b = get_parent(b, parent);
    if (a != b) // Если они не равны, то объединяем
    {
        if (rnk[a] < rnk[b]) // Если ранг родителя меньше ранга ребенка, то меняем их местами
        {
            swap(a, b);
        }
        parent[b] = a; // Присваиваем родителю ребенка
        if (rnk[a] == rnk[b]) // Если ранги равны, то увеличиваем ранг родителя
        {
            rnk[a]++; 
        }
    }
}

void initialize(int n, vector<int> &parent, vector<int> &rnk) // Функция инициализации массивов родителей и рангов
{
    parent.resize(n + 1); // Размер массива родителей равен количеству вершин + 1
    rnk.resize(n + 1); // Размер массива рангов равен количеству вершин + 1
    for (int i = 1; i <= n; i++) // Присваиваем родителям их индексы
    {
        parent[i] = i; // Родитель вершины i равен i
        rnk[i] = 0; // Ранг вершины i равен 0
    }
}

int main()
{
    vector <int> parent;
    vector <int> rnk;
    int n, d, a;
    cin >> n >> d >> a;
    vector <string> inpArr(n); // Массив строк, в котором хранятся ребра графа
    initialize(n, parent, rnk); // Инициализируем массивы родителей и рангов

    for (int i = 0; i < n; i++) // Вводим граф
    {
        cin >> inpArr[i];
    }

    map <pair <int, int>, bool> added; // Массив пар, в котором хранятся ребра, которые уже были добавлены в ответ

    vector<string> answArr(n); // Массив строк, в котором хранятся ответ

    for (int i = 0; i < n; i++) // Инициализируем массив ответа
    {
        answArr[i] = string(n, '0');  // Заполняем массив нулями
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) // Проходим по всем ребрам
    {
        for (int j = 0; j < n; j++) // Проходим по всем ребрам
        {
            // Если ребро не было добавлено в ответ и ребро не было добавлено в ответ в обратном порядке
            if (inpArr[i][j] == '1' and added.find({i, j}) == added.end() and added.find({j, i}) == added.end()) 
            { // Добавляем ребро в ответ
                added[ {i, j}] = true;
                // Если родители вершин не равны, то объединяем их
                if (get_parent(i + 1, parent) != get_parent(j + 1, parent))
                {
                    merge_set(i + 1, j + 1, parent, rnk);
                }
                else
                { // Иначе добавляем стоимость удаления ребра
                    ans += d;
                    answArr[i][j] = 'd';
                    answArr[j][i] = 'd';
                }
            }
        }
    }

    vector<int> parentsOf(n + 1, -1); // Массив, в котором хранятся родители вершин
    vector<int> notInAnsw; // Массив, в котором хранятся вершины, которые не были добавлены в ответ

    /*
    цикл по всем вершинам графа
    для каждой вершины находит корневую
    Затем в массиве parentsOf соответствующий элемент, 
    помечается как 1. 
    после выполнения массив parentsOf будет содержать информацию
    о том, какие вершины корни деревьев в лесу.
    */
    for (int i = 1; i <= n; i++)
    {
        parentsOf[get_parent(i, parent)] = 1; // Присваиваем родителям 1
    }
    for (int i = 1; i <= n; i++)
    {
        if (parentsOf[i] != -1) // Если родитель не равен -1, то добавляем его в массив вершин, которые не были добавлены в ответ
        {
            notInAnsw.push_back(i);
        }
    }
    for (int i = 1; i < notInAnsw.size(); i++) // Добавляем в ответ ребра, которые соединяют вершины, которые не были добавлены в ответ
    {
        answArr[notInAnsw[0] - 1][notInAnsw[i] - 1] = 'a';
        answArr[notInAnsw[i] - 1][notInAnsw[0] - 1] = 'a';
        ans += a;
    }

    cout << ans << endl; 
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << answArr[i][j]; 
        }
        cout << endl;
    }
    return 0;
}
