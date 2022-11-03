#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi cache;

void to_g(int n, vvi& ws)
{
    g = vvi(n + 1);
    for (vi e: ws) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
}

int cnt(int p, int v)
{
    if (g[v].size() == 1 && g[v][0] == p) return 1;
    int& ret = cache[v];
    if (ret != -1) return ret;
    ret = 1;
    for (int w: g[v]) {
        if (w == p) continue;
        ret += cnt(v, w);
    }
    return ret;
}

int solve(int p, int v)
{
    if (g[v].size() == 1 && g[v][0] == p) return abs(cnt(-1, 1) - 2 * 1);
    int ret = abs(cnt(-1, 1) - 2 * cnt(p, v));
    for (int w: g[v]) {
        if (w == p) continue;
        ret = min(ret, solve(v, w));
    }
    return ret;
}

int solution(int n, vvi ws)
{
    to_g(n, ws);
    cache = vi(n + 1, -1);
    return solve(-1, 1);
}