#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 105;
const int MAXH = 1005;
const int MAXK = 15;

int N, M, XA, YA, H, K;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> exits;
vector<pair<pair<int, int>, pair<int, int>>> tunnels;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

bool is_valid(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M && grid[x][y] == 0 && !visited[x][y];
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    dist[x][y] = 0;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (is_valid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cur_x][cur_y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}

int dijkstra(int x, int y) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {x, y} });

    while (!pq.empty()) {
        int cur_x = pq.top().second.first;
        int cur_y = pq.top().second.second;
        int cur_dist = pq.top().first;
        pq.pop();

        if (visited[cur_x][cur_y]) {
            continue;
        }

        visited[cur_x][cur_y] = true;

        if (find(exits.begin(), exits.end(), make_pair(cur_x, cur_y)) != exits.end()) {
            return cur_dist;
        }

        for (auto tunnel : tunnels) {
            int x1 = tunnel.first.first;
            int y1 = tunnel.first.second;
            int x2 = tunnel.second.first;
            int y2 = tunnel.second.second;

            if (cur_x == x1 && cur_y == y1) {
                pq.push({ cur_dist + dist[x2][y2] + 1, {x2, y2} });
            }
            else if (cur_x == x2 && cur_y == y2) {
                pq.push({ cur_dist + dist[x1][y1] + 1, {x1, y1} });
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (is_valid(nx, ny) && !visited[nx][ny]) {
                pq.push({ cur_dist + 1, {nx, ny} });
            }
        }
    }

    return -1;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> M >> XA >> YA >> H >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            fin >> grid[i][j];
            dist[i][j] = MAXH;
        }
    }

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        tunnels.push_back({ {x1, y1}, {x2, y2} });
    }

    for (int i = 1; i <= H; i++) {
        int x, y;
        fin >> x >> y;
        exits.push_back({ x, y });
    }

    bfs(XA, YA);

    int ans = MAXH;

    for (auto exit : exits) {
        int ex = exit.first;
        int ey = exit.second;
        if (dist[ex][ey] <= H) {
            ans = min(ans, dist[ex][ey]);
            continue;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                visited[i][j] = false;
            }
        }

        for (auto tunnel : tunnels) {
            int x1 = tunnel.first.first;
            int y1 = tunnel.first.second;
            int x2 = tunnel.second.first;
            int y2 = tunnel.second.second;

            if (dist[x1][y1] <= H && dist[x2][y2] <= H) {
                visited[x1][y1] = true;
                visited[x2][y2] = true;
            }
        }

        for (auto tunnel : tunnels) {
            int x1 = tunnel.first.first;
            int y1 = tunnel.first.second;
            int x2 = tunnel.second.first;
            int y2 = tunnel.second.second;

            if (dist[x1][y1] <= H) {
                int d = dijkstra(x2, y2);
                if (d != MAXH) {
                    ans = min(ans, dist[x1][y1] + d);
                }
            } else if (dist[x2][y2] <= H) {
                int d = dijkstra(x1, y1);
                if (d != MAXH) {
                    ans = min(ans, dist[x2][y2] + d);
                }
            }
        }
    }

    if (ans == MAXH) {
        fout << -1 << endl;
    } else {
        fout << ans << endl;
    }

    fin.close();
    fout.close();
    return 0;
}