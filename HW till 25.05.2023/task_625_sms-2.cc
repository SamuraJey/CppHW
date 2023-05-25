#include <iostream>
#include <string>
#include <vector>

enum State
{
    LOWERCASE,
    UPPERCASE,
    FIRST_CHAR
};

int buttonNumForChar(char c, const std::vector<int> &charToButtonNum) // Возвращаем номер кнопки для данного символа
{
    return charToButtonNum[static_cast<int>(c)]; // static_cast<int>(c) - приведение типа char к типу int, получаем код символа
}

int pressCountForChar(char c, const std::vector<int> &charToPressCount) // Возвращаем количество нажатий для данного символа
{
    return charToPressCount[static_cast<int>(c)]; // static_cast<int>(c) - приведение типа char к типу int, получаем код символа
}

bool isValidPunctuation(char c) // Проверяем, является ли символ знаком препинания
{
    return c == '.' || c == '!' || c == '?'; // Если да, то возвращаем true, иначе false
}

int main()
{
    std::vector<int> charToPressCount(128, -1);
    std::vector<int> charToButtonNum(128, -1);

    // Инициализируем переменные
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 2;
    const int FIRST_CHAR = 3;
    int state = FIRST_CHAR;
    int lastButton = 0;
    int count = 0;

    // Читаем раскладку клавиатуры
    for (int lineNum = 1; lineNum <= 9; lineNum++)
    {
        std::string line;
        std::cin >> line;
        for (char c : line)
        {
            int charCode = static_cast<int>(c);
            charToPressCount[charCode] = line.find(c) + 1;
            charToButtonNum[charCode] = lineNum;
        }
    }

    // Читаем входную строку
    std::string inputString;
    std::cin.ignore(); // Игнорируем предыдущий символ перевода строки
    std::getline(std::cin, inputString);

    // Перебираем все символы входной строки
    for (char currChar : inputString)
    {
        if (currChar == ' ') 
        {
            count++;
            lastButton = 0;
            continue;
        }
        if (isValidPunctuation(currChar)) // Проверяем, является ли символ знаком препинания
        {
            if (buttonNumForChar(currChar, charToButtonNum) == lastButton) // Проверяем, была ли нажата предыдущая кнопка
            {
                count++;
            }
            count += pressCountForChar(currChar, charToPressCount); // Прибавляем количество нажатий для данного символа
            if (state == LOWERCASE) // Проверяем, был ли предыдущий символ в нижнем регистре
            {
                state = FIRST_CHAR; // Если да, то переходим в состояние FIRST_CHAR
            }
            lastButton = buttonNumForChar(currChar, charToButtonNum); // Запоминаем номер кнопки, на которой был нажат символ
        }
        else if (islower(currChar)) // Проверяем, является ли символ строчной буквой
        {
            if (buttonNumForChar(currChar, charToButtonNum) == lastButton) // Проверяем, была ли нажата предыдущая кнопка
            {
                count++; // Если да, то прибавляем 1 к количеству нажатий
            }
            count += pressCountForChar(currChar, charToPressCount); // Прибавляем количество нажатий для данного символа
            if (state == UPPERCASE || state == FIRST_CHAR) // Проверяем, был ли предыдущий символ в верхнем регистре или является ли он первым символом в строке
            {
                count++; // Если да, то прибавляем 1 к количеству нажатий
                state = LOWERCASE; // Переходим в состояние LOWERCASE
            }
            lastButton = buttonNumForChar(currChar, charToButtonNum); // Запоминаем номер кнопки, на которой был нажат символ
        }
        else if (isupper(currChar)) // Проверяем, является ли символ заглавной буквой
        {
            if (buttonNumForChar(tolower(currChar), charToButtonNum) == lastButton) // Проверяем, была ли нажата предыдущая кнопка
            {
                count++; // Если да, то прибавляем 1 к количеству нажатий
            }
            count += pressCountForChar(tolower(currChar), charToPressCount); // Прибавляем количество нажатий для данного символа
            if (state == LOWERCASE) // Проверяем, был ли предыдущий символ в нижнем регистре
            {
                count++; // Если да, то прибавляем 1 к количеству нажатий
                state = UPPERCASE; // Переходим в состояние UPPERCASE
            }
            else if (state == FIRST_CHAR) // Проверяем, является ли предыдущий символ первым символом в строке
            {
                state = LOWERCASE; // Если да, то переходим в состояние LOWERCASE
            }
            lastButton = buttonNumForChar(tolower(currChar), charToButtonNum); // Запоминаем номер кнопки, на которой был нажат символ
        }
    }

    std::cout << count; // Выводим количество нажатий
    return 0;
}