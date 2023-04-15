#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class TextEditor 
{
public:
    void MoveCursorTo(int row, int col) // передвинуть курсор в позицию (row, col)
    {
        row = row;
        col = col;
    }

    void InsertChar(char c) // вставить символ c в текущую позицию курсора
    {
        operations.push_back(Operation('I', c));
        redoStack = stack<Operation>();
    }

    void DeleteChar() // удалить символ в текущей позиции курсора
    {
        operations.push_back(Operation('D'));
        redoStack = stack<Operation>();
    }

    void Undo() 
    {
        if (!operations.empty()) 
        {
            Operation lastOp = operations.back();
            operations.pop_back();

            if (lastOp.type == 'I') // если последняя операция была вставкой, то удаляем вставленный символ
            {
                DeleteChar();
            } 
            else if (lastOp.type == 'D') // если последняя операция была удалением, то вставляем удаленный символ
            {
                InsertChar(lastOp.c);
            }
            redoStack.push(lastOp);
        }
    }

    void Redo() 
    {
        if (!redoStack.empty()) 
        {
            Operation lastOp = redoStack.top();
            redoStack.pop();

            if (lastOp.type == 'I') // если последняя операция была вставкой, то вставляем вставленный символ
            {
                InsertChar(lastOp.c);
            } else if (lastOp.type == 'D') // если последняя операция была удалением, то удаляем удаленный символ
            {
                DeleteChar();
            }

            operations.push_back(lastOp);
        }
    }

private:
    struct Operation 
    {
        char type; // 'I' для вставки, 'D' для удаления
        char c;    // символ для вставки, используется только для I

        Operation(char t, char ch = '\0') : type(t), c(ch) {} // конструктор, где t - тип операции, ch - символ для вставки. type и c инициализируются значениями t и ch
    };

    vector<Operation> operations; // операции, которые были сделаны
    stack<Operation> redoStack; // операции, которые можно отменить
};
