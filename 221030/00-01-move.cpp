#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;
vvi candy, cache;

int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};

inline bool in_range(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

int max_candy(int i, int j)
{
    if (!in_range(i, j)) return 0;
    int &ret = cache[i][j];
    if (ret != -1) return ret;
    for (int d: {0, 1, 2}) {
        ret = max(ret, candy[i][j] + max_candy(i + dy[d], j + dx[d]));
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    candy = vvi(n, vi(m));
    cache = vvi(n, vi(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> candy[i][j];
        }
    }
    cout << max_candy(0, 0);
    return 0;
}