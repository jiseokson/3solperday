#include <string>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using pqii = priority_queue<ii>;

vector<int> solution(int n, vvi rs, vi ss, int dst) {
    vvi g(n + 1);
    for (vi& e: rs) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    
    const int inf = 987654321;
    pqii q;
    vi dist(n + 1, inf);
    q.push({-0, dst});
    dist[dst] = 0;
    while (!q.empty()) {
        int d = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (dist[v] < d) continue;
        for (int w: g[v]) {
            int dw = d + 1;
            if (dist[w] > dw) {
                dist[w] = dw;
                q.push({-dw, w});
            }
        }
    }
    
    vi ans;
    for (int& s: ss)
        ans.push_back(dist[s] < inf ? dist[s] : -1);
    return ans;
}