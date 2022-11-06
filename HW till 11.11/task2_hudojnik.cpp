#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    string filename = "input";
    string ofilename = "output";
    //string s;
    int arr[100][100];
    int w, h, n, x1, x2, y1, y2, answ = 0;

    ifstream input(filename);
    ofstream output(ofilename);
    input >> w >> h;
    input >> n;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {
            arr[i][j] = 0; }}
   while (n > 0)
   {
    input >> x1 >> y1 >> x2 >> y2;
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            arr[i][j] = 1; 
            }
        }
    n--;
    }

   for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == 0) {
                answ++;
            }
        }
   }
    output << answ;
    input.close();
    output.close();
}
