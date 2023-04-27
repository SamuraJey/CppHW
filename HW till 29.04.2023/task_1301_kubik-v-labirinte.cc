/* 1301. Cube in Labyrinth - http://acm.timus.ru/problem.aspx?num=1301
 *
 * Strategy:
 * Depth-first search through the maze while recording the shortest path to each position for
 * each configuration of the cube, terminating any branch whenever a shorter path than the
 * current was reached for the position and configuration of the branch.
 *
 * Performance:
 * O(XY), runs the tests in 0.001s using 404KB memory.
 */

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

int N[255]; // The neighboring edge of the index edge
unsigned int A[255][11][11]; // Smallest cost matrix
bool V[11][11][11][11]; // Visibility matrix
int m, n;
struct point { int x, y; };

// Checks if { sx, sy } -> { x, y } is a valid move
bool valid(int sx, int sy, int x, int y)
{
    return x <= m && y <= n && x > 0 && y > 0 && V[sx][sy][x][y];
}

// Returns the configuration given by rotating this configuration 90*deg degrees. A configuration
// is defined by the id of the leftmost edge of the top surface of the cube
int rotate(int s, int deg)
{
    return (s+deg)%4+(s&0xF0);
}

// Returns the face yielded by flipping this face along the given direction
int flip(int s, int dir)
{
    if(dir == 0) // Left
        return N[rotate(s, 2)];
    else if(dir == 1) // Up
        return rotate(N[rotate(s, 3)], 3);
    else if(dir == 2) // Right
       return rotate(N[s], 2); 
    else if(dir == 3) // Down
        return rotate(N[rotate(s, 1)], 1);
    return 0;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    std::string str;
    bool vertical;
    int a, b, c, d, x, y;
    std::memset(V, true, sizeof(V));
    std::memset(A, 255, sizeof(A));

    // Defines the neighboring (semi-)edge for the 4*6 (semi-)edges of the cube. A face is the
    // alphabetic part and the edge is the numeric part
    //N[160] = 177; N[161] = 243; N[162] = 209; N[163] = 193; N[200] = 161; N[201] = 177;
    


    // Defines the neighboring (semi-)edge for the 4*6 (semi-)edges of the cube. A face is the
    // alphabetic part and the edge is the numeric part
    N[160] = 177; N[161] = 243; N[162] = 209; N[163] = 193; N[208] = 194; N[209] = 162;
    N[210] = 242; N[211] = 226; N[192] = 178; N[193] = 163; N[194] = 208; N[195] = 225;
    N[176] = 240; N[177] = 160; N[178] = 192; N[179] = 224; N[224] = 179; N[225] = 195; 
    N[226] = 211; N[227] = 241; N[240] = 176; N[241] = 227; N[242] = 210; N[243] = 161;
    std::stack<std::pair<point, int>, std::vector<std::pair<point, int>>> s; // dfs stack

// Read


    // Read the input
    std::cin >> m >> n >> a >> b >> c >> d;
    while(std::cin >> str)
    {
        if(str[0] == 'v')
            vertical = true;
        else if(str[0] == 'h')
            vertical = false;
        else
        {
            x = std::stoi(str);
            std::cin >> y;
            if(vertical)
                V[x+1][y][x][y] = V[x][y][x+1][y] = false;
            else
                V[x][y][x][y+1] = V[x][y+1][x][y] = false;
        }
    }

    // Dfs
    const point dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    s.push( { { a, b }, 0xa0 } );
    A[0xa0][a][b] = 0;
    while(!s.empty())
    {
        auto p = s.top().first;
        auto side = s.top().second;
        s.pop();
        for(int i = 0; i < 4; i++)
        {
            auto d = dir[i];
            point pd = { p.x+d.x, p.y+d.y };
            if(valid(p.x, p.y, pd.x, pd.y))
            {
                auto newside = flip(side, i);
                if(A[newside][pd.x][pd.y] > A[side][p.x][p.y])
                {
                    A[newside][pd.x][pd.y] = A[side][p.x][p.y] + 1;
                    s.push( { { pd.x, pd.y }, newside } );
                }
            }
        }
    }
    unsigned int min = 999999999;
    for(int i = 0; i < 4; i++)
    {
        min = std::min(min, A[0xa0+i][c][d]);
    }
    if(min == 999999999)
        std::cout << "No solution";
    else
        std::cout << min;
}