#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 1000000007;

int h, w;
vvi pud;
vvi cache;

inline int in_range(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

int cnt_path(int y, int x)
{
    if (!in_range(y, x) || pud[y][x]) return 0;
    if (y == h - 1 && x == w - 1) return 1;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    return ret = (cnt_path(y + 1, x) + cnt_path(y, x + 1)) % mod;
}

int solution(int m, int n, vvi puddles) {
    h = m, w = n;
    pud = vvi(m, vi(n, 0));
    for (vi p: puddles)
        pud[p[0] - 1][p[1] - 1] = 1;
    cache = vvi(m + 1, vi(n + 1, -1));
    return cnt_path(0, 0);
}