#include <string>
#include <vector>
#include <iostream>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vvi cache;

void to_g(int n, vvi &l)
{
    g = vvi(n + 1);
    for (vi e: l) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
}

int is_leaf(int p, int v)
{
    for (int w: g[v])
        if (w != p)
            return 0;
    return 1;
}

int min_l(int p, int v, int on)
{
    if (is_leaf(p, v)) return on;
    int &ret = cache[v][on];
    if (ret != -1) return ret;
    ret = on;
    for (int w: g[v]) {
        if (w == p) continue;
        if (on)
            ret += min(min_l(v, w, 0), min_l(v, w, 1));
        else
            ret += min_l(v, w, 1);
    }
    return ret;
}

int solution(int n, vector<vector<int>> l) {
    to_g(n, l);
    cache = vvi(n + 1, vi(2, -1));
    return min(min_l(-1, 1, 0), min_l(-1, 1, 1));
}

int main(void)
{
    const int tc = 2;
    int n[tc] = {8, 10};
    vvi l[tc] = {
        {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {5, 6}, {5, 7}, {5, 8}},
        {{4, 1}, {5, 1}, {5, 6}, {7, 6}, {1, 2}, {1, 3}, {6, 8}, {2, 9}, {9, 10}}
    };
    for (int c = 0; c < tc; ++c)
        cout << solution(n[c], l[c]) << endl;
}