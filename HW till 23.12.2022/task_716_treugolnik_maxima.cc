#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n;
	cin >> n; // количество нот
	vector <double> ft(n); // массив частот нот
	vector <bool> cl(n); // массив результатов прослушивания
	string ss;
	cin >> ft[0];  // первая нота
	for (int z = 1; z < n; z++)
	{
		cin >> ft[z] >> ss; cl[z] = ss == "closer";
	}
	double max = 4000;
	double min = 30;
	for (int z = 1; z < n ; z++) 
	{
		if (ft[z - 1] != ft[z])
		{
			if ((ft[z - 1] < ft[z]) ^ cl[z])
			{
				if (max > (ft[z - 1] + ft[z]) / 2) max = (ft[z - 1] + ft[z]) / 2;
			}
		else
		{
			if (min < (ft[z - 1] + ft[z]) / 2) min = (ft[z - 1] + ft[z]) / 2;
		}
		}
		}
		cout << fixed << setprecision(7) << min << " " << max;
}