from collections import deque

def solution(n, es):
    g = [[] for _ in range(n + 1)]
    for e in es:
        g[e[0]].append(e[1])
        g[e[1]].append(e[0])
    maxd = 0
    ans = 0
    q = deque()
    dist = [-1 for _ in range(n + 1)]
    q.append(1)
    dist[1] = 0
    while q:
        v = q.popleft()
        if maxd == dist[v]:
            ans += 1
        elif maxd < dist[v]:
            maxd = dist[v]
            ans = 1
        for w in g[v]:
            if dist[w] != -1: continue
            q.append(w)
            dist[w] = dist[v] + 1
    return ans