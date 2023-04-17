#include "TextEditor.hh"

int main() 
{
    /* 
    Я не понимаю почему первый вызов метода Undo() не работает, после второго вызова он работает как надо.
    В целом функциональность работает
    */
    TextEditor editor;
    editor.InsertChar('H');
    editor.InsertChar('e');
    editor.InsertChar('l');
    editor.InsertChar('l');
    editor.InsertChar('o'); 

    editor.Print(); // Hello

    editor.DeleteChar();
    editor.DeleteChar();
    editor.Print(); // Hel
    editor.InsertChar('G');
    editor.Print();
    editor.Undo();
    editor.Undo();
    editor.Undo();
    editor.Print(); // Hell
}
