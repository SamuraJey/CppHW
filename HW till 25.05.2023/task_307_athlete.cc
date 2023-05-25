#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numSportsmen, numExercises, numOutputs;
    cin >> numSportsmen >> numExercises >> numOutputs;

    vector<vector<bool>> outputs(numSportsmen, vector<bool>(numExercises));
    for (int i = 0; i < numOutputs; ++i)
    {
        int sportsman, exercise;
        cin >> sportsman >> exercise;
        outputs[sportsman - 1][exercise - 1] = true;
    }

    vector<vector<int>> solutions(numSportsmen, vector<int>(numExercises));
    int numSurprises = 0;

    for (int i = numSportsmen - 1; i >= 0; --i)
    {
        for (int j = 0; j < numExercises; ++j)
        {
            if (i < numSportsmen - 1 && j > 0 && outputs[i][j])
            {
                numSurprises += solutions[i + 1][j - 1];
            }
            int value = 0;
            if (outputs[i][j])
            {
                value += 1;
            }
            if (i < numSportsmen - 1)
            {
                value += solutions[i + 1][j];
            }
            if (j > 0)
            {
                value += solutions[i][j - 1];
            }
            if (i < numSportsmen - 1 && j > 0)
            {
                value -= solutions[i + 1][j - 1];
            }
            solutions[i][j] = value;
        }
    }

    cout << numSurprises;
}