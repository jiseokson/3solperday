#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using qii = queue<ii>;

int n, m;

inline int in_range(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

int main(void)
{
    cin >> n >> m;
    vs maze(n);
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }
    qii q;
    vvi dist(n, vi(m, 0));
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    q.push(make_pair(0, 0));
    dist[0][0] = 1;
    while (!q.empty()) {
        ii cur = q.front();
        q.pop();
        int y = cur.first;
        int x = cur.second;
        if (y == n - 1 && x == m - 1) {
            break;
        }
        for (int d: {0, 1, 2, 3}) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (!in_range(ny, nx) || maze[ny][nx] != '1' || dist[ny][nx] > 0) continue;
            q.push(make_pair(ny, nx));
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
    cout << dist[n - 1][m - 1];
    return 0;
}