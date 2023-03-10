#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
    int x, y;
    ifstream input = OpenFile("input971.txt");
    ofstream output = OutputFile("output971.txt");
    input >> x >> y;
    if (abs(x) >= 1000000000 || abs(y) >= 1000000000) // Значения за пределами
    {
        output << "NO"; 
        return 0;
    }

    output << "YES" << endl;
    
    if (y < 999999999) // есть 2 варианта для любого треугольника "носом" вверх
    { 
        output << x - 1 << " " << y - 1 << endl;
        output << x << " " << y + 2 << endl;
        output << x + 1 << " " << y - 1;
    }
    else // носом вниз
    { 
        output << x - 1 << " " << y + 1 << endl;
        output << x << " " << y - 2 << endl;
        output << x + 1 << " " << y + 1;
    }
    input.close();
    output.close();
    return 0;
}