#include <iostream>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

ifstream OpenFile(string input_file)
{
    string filename = input_file;
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        input.close();
        return input;
    }
    return input;
}
ofstream OutputFile(string output_file)
{
    string ofilename = output_file;
    ofstream output(ofilename);
    return output;
}

/*
Так как мы принимаем на вход цифры в троичной системе счисления, нам удобнее записать их в строку
и потом сделать перевод их строки с троичным значением в десятичные целочисленные значения
*/
long long FromStringToTenBase(string a) { // Фунция перевода из строки в десятичные значения
    long long x = 0;
    for (int i = 0; i < a.length(); i++)
        x += int(a[a.length() - i - 1] - '0') * pow(3, i);
    return x;
}

int main() {
    ifstream input = OpenFile("input.txt");
    ofstream output = OutputFile("output.txt");

    string n, m;

    input >> n >> m;
    output << FromStringToTenBase(n) + FromStringToTenBase(m);

    input.close();
    output.close();

    return 0;
}

