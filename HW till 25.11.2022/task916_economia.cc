#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

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
    ifstream input = OpenFile("input916.txt");
    ofstream output = OutputFile("output916.txt");

    int  n, k;  // бутылок, друзей
    input >> n >> k;
    long long sum = 0;
    vector <long long> c(n);

    for (int i = 0; i < n; i++)
    {
        input >> c[i];
    }

    sort(c.begin(), c.end());
    reverse(c.begin(), c.end()); // дорогие бутылки покупаем в первую очередь

    for (int i = 0; i < n / k; i++) // вот столько полных кругов сделаем
    {   
        for (int j = 0; j < k; j++)
        {
            sum += (i + 1) * c[i * k + j];
        }
    }

    for (int i = k * (n / k); i < n; i++) // остаток
    { 
        sum += (n / k + 1) * c[i];
    }

    output << sum;
    input.close();
    output.close();
    return 0;
}