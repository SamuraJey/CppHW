#include <iostream>
#include <string>
#include <fstream>
#define Unknown 1001       // граница максимума и минимума

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

int main() {
    ifstream input = OpenFile("input388.txt");
    ofstream output = OutputFile("output388.txt");
    int n, m, uf = 0;
    int maxi;
    input >> n >> m;             // вводим размер таблицы
    int ** x = new int *[n];   // создаем массив длиной n
    for (int i = 0; i < n; i++)
    {
        x[i] = new int[m];         // создаем массив массивов
    }
            
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            input >> x[i][j]; // вводим данные в созданную таблицу
        }
    }

    int  max[751];                    // создаем массив и забиваем его значениями 1001
    for (int i = 0; i < m; i++)
    {
        max[i] = Unknown;
    }
    for (int i = 0; i < n; i++) 
    {
        int min = x[i][0];
        for (int j = 1; j < m; j++) 
        {
            if (min > x[i][j])
            { 
                min = x[i][j]; // находим минимум в строке
            }
            }
            for (int j = 0; j < m; j++)
            {
                if (x[i][j] == min) // если ячейка равна минимуму
                {      
                    if (max[j] != Unknown) 
                    { // ищем в колонке максимум
                        maxi = max[j];
                    }
                        else 
                        {
                            maxi = x[i][j];
                            for (int l = 0; l < n; l++)
                            {
                                if (maxi < x[l][j]) 
                                {
                                    maxi = x[l][j];
                                }
                            }
                            max[j] = maxi; // и помещаем его в массив максимумов для этой колонки
                        }
                        if (maxi == min) uf++;
                        // ежели минимум и максимум равны, считаем их
                }
            }
    }
    output << uf;
    input.close();
    output.close();
    return 0;
}