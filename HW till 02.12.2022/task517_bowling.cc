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
    ifstream input = OpenFile("input517.txt");
    ofstream output = OutputFile("output517.txt");

    unsigned int num, answ = 0, counter = 0;
    input >> num;
    vector <int> arr(num);
    for (int i = 0; i < num; i++)
    {
        input >> arr[i];
    }
    for (int i = 0; i < 10; i++)
    {
        answ += arr[counter];
        if (arr[counter] == 10)
        {
            answ += arr[counter + 1];
            answ += arr[counter + 2];
            counter++;
            continue;
        }
        answ += arr[counter + 1];
        if (arr[counter] + arr[counter + 1] == 10)
        {
            answ += arr[counter + 2];
            counter += 2;
            continue;
        }
        counter += 2;
    }
    cout << answ <<  endl;
    



    input.close();
    output.close();
    return 0;
}
