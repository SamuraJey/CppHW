#include <iostream>
#include <string>

using namespace std;

struct Pair 
{
    string key;
    int value;
};

// структура хеш-таблицы
struct HashTable 
{
private:
    Pair* table; // Массив пар ключ-значение
    int size; // Размер массива
    int count; // Количество элементов в хеш-таблице

    // Хеш-функция
    int Hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) 
        {
            hash += key[i];
        }
        return hash % size;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table = new Pair[size];
        count = 0;
    }

    ~HashTable() 
    {
        delete[] table;
    }

    //добавление элемента в хеш-таблицу
    void Put(string key, int value)
    {
        if (count == size)
        {
            cout << "Хеш-таблица заполнена" << endl;
            return;
        }
        int index = Hash(key);
        while (table[index].key != "" && table[index].key != key)
        {
            index = (index + 1) % size;
        }
        if (table[index].key == "")
        {
            count++;
        }
        table[index] = {key, value};
    }

    //поиск элемента в хеш-таблице по ключу
    int Get(string key) 
    {
        int index = Hash(key);
        int startIndex = index;
        while (table[index].key != "" && table[index].key != key) 
        {
            index = (index + 1) % size;
            if (index == startIndex) 
            {
                // достигнут начальный индекс - элемент не найден
                return -1;
            }
        }
        if (table[index].key == "")
        {
            // элемент не найден
            return -1;
        }
        return table[index].value;
    }

    //удаление элемента из хеш-таблицы
    void Remove(string key)
    {
        int index = Hash(key);
        int startIndex = index;
        while (table[index].key != "" && table[index].key != key)
        {
            index = (index + 1) % size;
            if (index == startIndex)
            {
                // достигнут начальный индекс - элемент не найден
                return;
            }
        }
        if (table[index].key == "")
        {
            // элемент не найден
            return;
        }
        table[index].key = "";
        table[index].value = -1;
        count--;
    }
};

int main() {

    HashTable hashTable(4);

    hashTable.Put("John", 35);
    hashTable.Put("Mary", 27);
    hashTable.Put("Bob", 42);
    hashTable.Put("Johne", 35);

    cout << hashTable.Get("John") << endl;
    cout << hashTable.Get("Mary") << endl;
    cout << hashTable.Get("Bob") << endl;
    hashTable.Remove("Bob");
    cout << hashTable.Get("Bob") << endl;


    return 0;
}

/*
Если в ячейке с вычисленным индексом уже находится другой элемент с другим ключом, 
то происходит линейное пробирование - вычисляется новый индекс
по формуле (index + 1) % size. 
Поиск подходящей ячейки продолжается до тех пор, 
пока не будет найдена свободная ячейка или элемент с таким же ключом.
*/