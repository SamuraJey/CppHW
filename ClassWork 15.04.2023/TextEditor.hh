#include <iostream>
#include <vector>

using namespace std;

class TextEditor 
{
public:
    TextEditor() 
    {
        cursor_row = cursor_col = 0;
        changes.push_back(""); // начинаем с пустой строки
        current_change = 0;
    }

    void MoveCursorTo(int row, int col)
    {
        cursor_row = row;
        cursor_col = col;
    }

    void InsertChar(char c) // метод для вставки символа
    {
    int pos = cursor_row * ROW_SIZE + cursor_col; // Позиция курсора
    if (pos > changes[current_change].size()) // Если позиция курсора больше размера строки
    {
        pos = changes[current_change].size(); // То позиция курсора равна размеру строки
    }
    changes[current_change].insert(pos, 1, c); // В векторе changes по индексу current_change вставляем символ с позиции pos
    cursor_col++;
    if (cursor_col == ROW_SIZE) 
    {
        cursor_col = 0;
        cursor_row++;
    }
    if (cursor_row * ROW_SIZE + cursor_col > changes[current_change].size()) 
    {
        changes[current_change].resize(cursor_row * ROW_SIZE + cursor_col, ' ');
    }
    current_change++;
    changes.resize(current_change + 1);
    changes[current_change] = changes[current_change - 1]; // // Копируем в вектор changes по индексу current_change строку по индексу current_change - 1
}


    void DeleteChar() // Метод "Удалить символ"
    {
        if (cursor_col > 0) 
        {
            changes[current_change].erase(cursor_row * ROW_SIZE + cursor_col - 1, 1); // в векторе changes по индексу current_change удаляем символ с позиции cursor_row * ROW_SIZE + cursor_col - 1 
            cursor_col--;
        } 
        else if (cursor_row > 0) // Если курсор находится в начале строки, то перемещаем его в конец предыдущей строки
        {
            cursor_row--; // Перемещаем курсор на одну строку вверх
            cursor_col = ROW_SIZE - 1; // Перемещаем курсор в конец строки
            changes[current_change].erase(cursor_row * ROW_SIZE + cursor_col, 1); // Удаляем символ с позиции cursor_row * ROW_SIZE + cursor_col
        }
        current_change++;
        changes.resize(current_change + 1); // Увеличиваем размер вектора changes на 1
        changes[current_change] = changes[current_change - 1]; // Копируем в вектор changes по индексу current_change строку по индексу current_change - 1
    }

    void Undo() // Метод "Отменить"
    {
        if (current_change > 0) 
        {
            //cout << "undo" << endl;
            current_change--;
            int pos = cursor_row * ROW_SIZE + cursor_col;
           // cout << "pos = " << pos << endl;
            //cout << "current_change = " << current_change << endl;
           // cout << "changes[current_change] = " << changes[current_change] << endl;
            if (pos > changes[current_change].size()) 
            {
                pos = changes[current_change].size();
            }
            cursor_row = pos / ROW_SIZE;
            cursor_col = pos % ROW_SIZE;
        }
    }

    void Redo() // Метод "Повторить"
    {
        if (current_change < changes.size() - 1) 
        {
            current_change++;
            int pos = cursor_row * ROW_SIZE + cursor_col;
            if (pos > changes[current_change].size()) 
            {
                pos = changes[current_change].size();
            }
            cursor_row = pos / ROW_SIZE;
            cursor_col = pos % ROW_SIZE;
        }
    }

    void Print() 
    {
        for (int i = 0; i < changes[current_change].size(); i++) // Вывод строки
        {
            cout << changes[current_change][i];
            if ((i + 1) % ROW_SIZE == 0) 
            {
                cout << endl;
            }
        }
        cout << endl;
    }

private:
    int counter = 0;
    const int ROW_SIZE = 10; // Размер строки
    int cursor_row, cursor_col; // Позиция курсора
    vector<string> changes; // вектор для хранения изменений
    int current_change; // индекс текущего изменения
};