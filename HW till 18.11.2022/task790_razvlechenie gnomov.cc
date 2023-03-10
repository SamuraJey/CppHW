#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Convert(int end_base, int num) //Функция перевода из десятичной системы счисления в сс с основанием end_base
{
    string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res = "";
    while (num > 0) 
    {
        res = alphabet[num % end_base] + res;
        num = num / end_base;
    }
    return res;
}

int main()
{
    string date = "";
    string day = "";
    string month = "";
    string year = "";
    string answ = "";
    int counter = 0;
    int intday = 0;
    int intmonth = 0;
    int intyear = 0;

    string filename = "input790.txt";
    string ofilename = "output790.txt";
    ifstream input(filename);

    if (!input)
    {
        std::cout << "Error opening file" << std::endl;
        return 0;
    }
    ofstream output(ofilename);

    input >> date;

    while (isdigit(date[counter])) // читаем в переменную day date с индексом counter, пока date[counter] число, по аналогии делаем с месяцем и годом
    {
        day = day + date[counter];
        counter++;
    }

    counter++;

    while (isdigit(date[counter]))
    {
        month = month + date[counter];
        counter++;
    }

    counter++;

    while (isdigit(date[counter]))
    {
        year = year + date[counter];
        counter++;
    }

    intday = stoi(day); // stoi = string to int переводит число записанное в string в число типа int 
    intmonth = stoi(month);
    intyear = stoi(year);

    day = Convert(intday + 1, intday); // вызываем нашу функцию для перевода из 10-ой сс в intday+1 по условию
    month = Convert(intday + 1, intmonth);
    year = Convert(intday + 1, intyear);

    answ = day + "/" + month + "/" + year;
    output << answ;

    input.close();
    output.close();
    return 0;
}

/*
условия
Развлечения гномов
(Время: 1 сек. Память: 16 Мб Сложность: 28%)

Гномы свободно владеют системами счисления с разными основаниями и достигли они этого ежедневными тренировками. Именно поэтому каждое утро у гномов начинается с того, что они текущую календарную дату переводят в другую систему счисления. Ваше задание такое же: перевести заданную дату D/M/Y в систему счисления с основанием D+1.

Для обозначения цифр больших 9 используются большие английские буквы в алфавитном порядке.
Входные данные

Входной файл INPUT.TXT содержит строку, содержащую дату в формате D/M/Y в десятичной системе счисления (1 ≤ D ≤ 31, 1 ≤ M ≤ 12, 1 ≤ Y ≤ 9999).
Выходные данные

В выходной файл OUTPUT.TXT выведите одну строку – дату в формате D/M/Y в системе счисления с основанием D+1.
Пример
№	INPUT.TXT	OUTPUT.TXT
1	1/10/2000	1/1010/11111010000
*/