#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
    ifstream input = OpenFile("input54.txt");
    ofstream output = OutputFile("output54.txt");

    int n, m;
    input >> n >> m;
    double ig[101][101];
    
    for (int z = 0; z < n; z++)
    {
        for (int x = 0; x < m; x++)
        {
            input >> ig[z][x];
        }
    }

    if (n == 1 && m == 1) { cout << ig[0][0] << " " << ig[0][0]; return 0; }

    vector <double> mmx;
    vector <double> mmn;
    
    // ищем нижнее значение игры
    for (int z = 0; z < n; z++)
    {
        double mmin = ig[z][0];
        if (m > 1) // Если больше одной колонки
        {
            for (int x = 1; x < m; x++) mmin = min(mmin, ig[z][x]); // находим минимум в строке
            mmn.push_back(mmin); // помещаем минимум в массив минимумов
        }
        else mmn.push_back(ig[z][0]); // помещаем ячейку в массив минимумов
    }

    // ищем верхнее значение игры
    for (int x = 0; x < m; x++)
    {
        double mmax = ig[0][x];
        if (n > 1) // Если больше одной строки
        { 
        for (int z = 1; z < n; z++)
        {
            mmax = max(mmax, ig[z][x]); // находим максимум в колонке
        }  
        mmx.push_back(mmax); // помещаем максимум в массив максимумов
        }
        else mmx.push_back(ig[0][x]); // помещаем ячейку в массив максимумов
    }

    sort(mmn.begin(), mmn.end());
    output << mmn[n-1] << " ";   // выводим максимальный из минимумов
    sort(mmx.begin(), mmx.end());
    output << mmx[0];            // выводим минимальный из максимумов
    input.close();
    output.close();
    return 0;
}