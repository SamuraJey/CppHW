#include <iostream>
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

int main(int argc, char const *argv[])
{
    ifstream input = OpenFile("i546.txt");
    ofstream output = OutputFile("o546.txt");

    int n, pages;
    input >> n;
    pages = n / 4;
    if (n % 4 > 0)
    {
        pages++;
    }
    for (int i = 0; i < pages; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            output << i + 1 << " " << j + 1 << " ";
            if (j == 0)
            {
                if ((4 * pages - 2 * i) > n)
                {
                    output << '0' << ' ';
                }
                else
                {
                    output << 4 * pages - 2 * i << ' ';
                }
            }
            else
            {
                if ((i + 1) * 2 > n)
                {
                    output << '0' << ' ';
                }
                else
                {
                    output << (1 + i) * 2 << ' ';
                }
            }
            if (j == 0)
            {
                if (2 * i + 1 > n)
                {
                    output << '0' << endl;
                }
                else
                {
                    output << (2 * i + 1) << endl;
                }
            }
            else
            {
                if ((4 * pages - 2 * i - 1)>n)
                {
                    output << '0' << endl;
                }
                else
                {
                    output << 4 * pages - 2 * i - 1 << endl;
                }
            }
        }
    }
    input.close();
    output.close();
    return 0;
}