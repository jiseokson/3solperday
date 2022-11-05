#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi cache;

int max_path(vvi& tri, int y, int x)
{
    if (y == tri.size()) return 0;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    return ret = tri[y][x] + max(max_path(tri, y + 1, x), max_path(tri, y + 1, x + 1));
}

int solution(vvi tri)
{
    cache = vvi(tri.size() + 1, vi(tri.size() + 1, -1));
    return max_path(tri, 0, 0);
}