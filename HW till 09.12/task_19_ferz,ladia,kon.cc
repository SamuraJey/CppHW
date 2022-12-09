#include <iostream>
#include <string>
using namespace std;

bool queen(char z, char x, string fr)// ферзь бьет эту позицию?
{
    bool a = (z == fr[0] || x == fr[1]);
    a = a || (abs(z - fr[0]) == abs(x - fr[1]));
    return a;
}
bool rook(char z, char x, string ld) //ладья бьет эту позицию?
{ 
    return (z == ld[0] || x == ld[1]);
}
bool knight(char z, char x, string kn) // конь бьет эту позицию?
{ 
    bool a = (abs(z - kn[0]) == 1 && abs(x - kn[1]) == 2);
    a = a || (abs(z - kn[0]) == 2 && abs(x - kn[1]) == 1);
    return a;
}

int main()
{
    string fr, kn, ld;
    cin >> fr >> ld >> kn;
    int answ = 0;
    for (char z = 'A'; z <= 'H'; z++)
            for (char x = '1'; x < '9'; x++)
            {
                string zz = "00"; zz[0] = z; zz[1] = x;
                if (zz != fr && zz != kn && zz != ld)
                {
                    if (queen(z, x, fr) || knight(z, x, kn) || rook(z, x, ld)) 
                    {
                        answ++;
                    }
                }
            }

    cout << answ;
    return 0;
}
