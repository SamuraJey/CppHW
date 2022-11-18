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