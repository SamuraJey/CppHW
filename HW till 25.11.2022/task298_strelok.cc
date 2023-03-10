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

int main(int argc, char const *argv[])
{
    /*
    string filename = "input234.txt";
    string ofilename = "output234.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        input.close();
        return 1;
    }
    */
    //ofstream output(ofilename);

    int number, answ = 0;
    ifstream input = OpenFile("input298.txt");
    ofstream output = OutputFile("output298.txt");
    input >> number;
    vector <int> x(number);
    vector <int> y(number);
    vector <bool> is_hit(number, 1);
    
    for (int i = 0; i < number - 1; i++)
    {
        input >> x[i] >> y[i];
    }
    for (size_t i = 0; i < number; i++)
    {
        if (is_hit[i])
        {
            for (int j = i + 1; j < number; j++)
            {
                if ((is_hit[j]) && (x[i] * x[j] == y[i]) && x[i] * x[j] >= 0 && y[i] * y[j] >= 0)
                {
                    is_hit[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < number; i++)
    {
        answ += is_hit[i];
    }
    output << answ;
    input.close();
    output.close();
    return 0;
}
