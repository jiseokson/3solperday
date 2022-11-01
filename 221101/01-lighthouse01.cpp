#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using pqii = priority_queue<ii>;

vvi g;
vi on, check;
pqii q;

void to_g(int n, vvi &l)
{
    g = vvi(n + 1);
    for (vi e: l) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
}

int cnt_off(int v)
{
    int ret = 0;
    if (!check[v]) ++ret;
    for (int w: g[v]) {
        if (!check[w])
            ++ret;
    }
    return ret;
}

void set_check(int v)
{
    check[v] = 1;
    for (int w: g[v]) {
        check[w] = 1;
    }
}

int is_off(int n)
{
    for (int i = 1; i <= n; ++i)
        if (!check[i]) return 1;
    return 0;
}

int solution(int n, vector<vector<int>> l) {
    int answer = 0;
    to_g(n, l);
    on = vi(n + 1, 0);
    check = vi(n + 1, 0);
    while(is_off(n)) {
        q = pqii();
        for (int v = 1; v <= n; ++v) {
            if (on[n]) continue;
            q.push(make_pair(cnt_off(v), v));
        }
        on[q.top().second] = 1;
        set_check(q.top().second);
        q.pop();
        ++answer;
    }
    return answer;
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