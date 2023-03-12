#include <iostream>
#include <string>

using namespace std;

bool FerzCanBeat(int row, int col, string ferz) 
{
    return (col == ferz[0] - 'A' || row == ferz[1] - '1' || abs(col - (ferz[0] - 'A')) == abs(row - (ferz[1] - '1')));
}

bool LadiaCanBeat(int row, int col, string ladia) 
{
    return (col == ladia[0] - 'A' || row == ladia[1] - '1');
}

bool KonCanBeat(int row, int col, string kon)
{
    return (abs(col - (kon[0] - 'A')) == 1 && abs(row - (kon[1] - '1')) == 2) ||
           (abs(col - (kon[0] - 'A')) == 2 && abs(row - (kon[1] - '1')) == 1);
}

int main()
{
    string ferz, kon, ladia;
    cin >> ferz >> ladia >> kon;
    int s = 0;

    if (ferz[0] > 'H' || ladia[0] > 'H' || ferz[0] > 'H' || ferz[1] > '8' || ladia[1] > '8' || ferz[1] > '8')
    {
        cout << "wrong input" << endl;
        return 1;
    }

    for (int i = 0; i < 64; i++)
    {
        int row = i / 8;
        int col = i % 8;
        string coord = "A1";
        coord[0] += col;
        coord[1] += row;

        if (coord != ferz && coord != kon && coord != ladia)
        {
            if (FerzCanBeat(row, col, ferz) || KonCanBeat(row, col, kon) || LadiaCanBeat(row, col, ladia))
            {
                s++;
            }
        }
    }
    cout << s;
    return 0;
}
