#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using pqii = priority_queue<ii>;

const int inf = 987654321;

int main(void)
{
    int vcnt, ecnt, init;
    cin >> vcnt >> ecnt;
    cin >> init;
    vvii g(vcnt + 1);;
    for (int i = 0; i < ecnt; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    pqii pq;
    vi dist(vcnt + 1, inf);
    pq.push({0, init});
    dist[init] = 0;
    while (!pq.empty()) {
        int d = -pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (dist[v] < d) continue;
        for (ii& e: g[v]) {
            int w = e.first;
            int dw = d + e.second;
            if (dist[w] < dw) continue;
            dist[w] = dw;
            pq.push({-dw, w});
        }
    }
    for (int i = 1; i <= vcnt; ++i) {
        if (dist[i] < inf) cout << dist[i];
        else cout << "INF";
        cout << "\n";
    }
    return 0;
}