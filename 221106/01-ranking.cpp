#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using qi = queue<int>;

vvi g;
vvi res;

int solve(int n, int init)
{
    qi q;
    vi check(n + 1, 0);
    q.push(init);
    check[init] = 1;
    int up_cnt = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w: g[v]) {
            if (check[w] || res[w][v] != 1) continue;
            ++up_cnt;
            q.push(w);
            check[w] = 1;
        }
    }
    
    q = qi();
    check = vi(n + 1, 0);
    q.push(init);
    check[init] = 1;
    int down_cnt = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w: g[v]) {
            if (check[w] || res[w][v] != -1) continue;
            ++down_cnt;
            q.push(w);
            check[w] = 1;
        }
    }
    
    return up_cnt + down_cnt == n - 1;
}

int solution(int n, vvi ress)
{
    g = vvi(n + 1);
    res = vvi(n + 1, vi(n + 1, 0));
    for (vi r: ress) {
        g[r[0]].push_back(r[1]);
        g[r[1]].push_back(r[0]);
        res[r[0]][r[1]] = 1;
        res[r[1]][r[0]] = -1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (solve(n, i)) ++ans;
    return ans;
}