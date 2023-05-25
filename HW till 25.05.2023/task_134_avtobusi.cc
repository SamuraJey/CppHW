#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Edge
{
    int from, to, startTime, endTime;
    Edge(int from, int to, int startTime, int endTime)
        : from(from), to(to), startTime(startTime), endTime(endTime){};
};

const int INF = numeric_limits<int>::max();

int main()
{
    int numVillages, startVillage, endVillage, numRoutes;
    int fromVillage, toVillage, startTime, endTime;
    vector<Edge> routes;

    cin >> numVillages >> startVillage >> endVillage >> numRoutes;
    for (int i = 1; i <= numRoutes; i++)
    {
        cin >> fromVillage >> startTime >> toVillage >> endTime;
        routes.push_back(Edge(fromVillage, toVillage, startTime, endTime));
    }

    vector<int> timeToReach(numVillages + 1, INF);
    timeToReach[startVillage] = 0;

    while (true)
    {
        bool isFinalDestanation = false;
        for (int i = 0; i < numRoutes; i++)
        {
            if (timeToReach[routes[i].from] < INF && timeToReach[routes[i].from] <= routes[i].startTime && routes[i].endTime < timeToReach[routes[i].to])
            {
                timeToReach[routes[i].to] = routes[i].endTime;
                isFinalDestanation = true;
            }
        }
        if (!isFinalDestanation)
        {
            break;
        }
    }
    cout << (timeToReach[endVillage] < INF ? timeToReach[endVillage] : -1);
    return 0;
}