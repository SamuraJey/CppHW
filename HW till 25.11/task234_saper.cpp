#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename = "input234.txt";
    string ofilename = "output234.txt";
    ifstream input(filename);

    if (!input){
        std::cout << "Error opening file" << std::endl;
        input.close();
        return 1;
    }

    ofstream output(ofilename);
    
    int n, m, k, x, y;
    input >> n >> m >> k;
    char field[202][202];
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            field[i][j] = '0';
        }
    }
    for (int i = 0; i < k; i++)
    {
        input >> x >> y;
        field[x][y] = '*';
        if (field[x - 1][y - 1] != '*') field[x - 1][y - 1]++;
        if (field[x - 1][y] != '*') field[x - 1][y]++;
        if (field[x - 1][y + 1] != '*') field[x - 1][y + 1]++;
        if (field[x][y - 1] != '*') field[x][y - 1]++;
        if (field[x][y + 1] != '*') field[x][y + 1]++;
        if (field[x + 1][y - 1] != '*') field[x + 1][y - 1]++;
        if (field[x + 1][y] != '*') field[x + 1][y]++;
        if (field[x + 1][y + 1] != '*') field[x + 1][y + 1]++;
    }

    for (int j = 1; j < n + 1; j++)
    {
        for (int x = 1; x < m + 1; x++)
        {
            if (field[j][x] == '0')
            {
                output << '.';
            }
            else
            {
                output << field[j][x];
            }
        }
    output << endl;
    }
    
    input.close();
    output.close();
    return 0;
}
