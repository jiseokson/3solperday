## Floyd-Warshall ##
dist[i, j, k]: {1, 2, ... k} 집합 중 하나를 경유지로 하는 i에서 j로의 최단경로  
이러한 경로는 k를 통과하거나 k를 통과하지 않거나(i에서 k까지와 k에서 j까지의 최단경로가 {1, 2, ... k - 1}의 원소로만 이루어짐) 둘 중 하나에 속한다. 따라서 dist[i, j, k] = min(dist[i, j, k], dist[i, k, k - 1] + dist[k, j, k - 1]), dist[i, j, 0] = w[i, j]  
dp알고리즘이고 문제의 구조를 여러 상황에 응용할 수 있다. 이 알고리즘이 dp라는 것과 부분문제의 구조를 잘 기억해두자.
```C++
// dist[i][j] = w[i][j];
// next[i][j] = j;

for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            next[i][j] = next[i][k];
        }
    }
}
```
<br>

## Dijkstra ##
초기점으로부터 꼭짓점까지의 거리 dist를 단계적으로 개선(완화)시키는 알고리즘.  
pair<int, int>는 사전식 순서처럼 대소를 비교.  
priority_queue는 가장 큰 요소가 top()에 위치함.  
따라서 노드까지의 거리를 부호 반전해 first에 저장하면 가장 가까운 거리의 노드가 top()에 위치하게 할 수 있다. 다른 방식으로도 구현할 수 있지만 기본적으로 정의된 연산만을 이용한 가장 간단한 구현이므로 외워두자.
```C++
pq.push(init);
dist[init] = 0;

while (!pq.empty()) {
    int d = -pq.top().first;
    int v = pq.top().second;
    if (dist[v] < d) continue; // v까지의 거리가 이미 최적화되었다면 현재 요소 무시
    for (int e: g[v]) {
        int w = e.first;
        int dw = d + e.second;
        if (dist[w] > dw) {
            pq.push({-dw, w});
            dist[w] = dw;
            prev[w] = v;
        }
    }
}
```

## 01. 순위 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/49191
<br>

첫 번째 구현:
```C++
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
```
res[w][v]: w가 v에게 이긴 경우 1인 배열  
init으로부터 이긴 선수들로만 순회를 하며 init을 이긴 사람의 수를 셈. 같은 구조로 init이 이긴 사람의 수를 세는 코드도 작성. init을 이긴 사람과 init이 이긴 경기의 수의 합이 n - 1이라면 init은 등수가 결정되는 선수이다.  
한 선수당 두번의 bfs탐색을 하므로 시간복잡도 O(V * (V + E))가 소요되지만 |V| <= 100, |E| <= 1000에서는 충분히 빠른 시간안에 동작할 수 있다.(똑똑한 풀이는 아니지만)
<br>

다른 분의 구현:
```C++
vvi win(n + 1, vi(n + 1, 0));
for (vi& res: ress)
    win[res[0]][res[1]] = 1;
for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            win[i][j] = win[i][j] || (win[i][k] && win[k][j])
```
플로이드 워셜 알고리즘의 변형으로 보인다. 부분문제의 정의를 다음으로 하자.  
win[i][j][k]: 승부가 결정되는 경기들로 경로를 만들 때 {1, 2, ... k}를 경유해 i가 j를 이길 수 있다면 1  
win[i][j][0] = win[i][j] (base condition)  
win[i][j][k] = win[i][j][k - 1] || (win[i][k][k - 1] && win[k][j][k - 1])  
k단계의 부분문제를 해결하는데 k - 1단계의 부분문제만 사용하므로 결과를 누적하는 반복적인 방식으로 구현할 수 있다. 이때 win[i][j]와 win[j][i]의 누적은 i를 이긴 선수의 수와 i가 이긴 경기의 수의 합과 같다. i를 이긴 선수의 수와 i가 이긴 경기의 수의 합이 n - 1이라면 i의 등수는 결정가능하다. 따라서 win[i][j]와 win[j][i]의 누적을 모든 선수에 대해서 조사해 순위를 결정할 수 있는 선수의 수를 셀 수 있다.
<br>

## 02. 모음 사전 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/84512
<br>

사전에 존재하는 모든 단어를 사전순으로 완전탐색하며 target을 찾을 경우 1을 반환함. target을 찾지 못했는데 길이가 5 이상인 경우는 더 이상 답을 찾지 못하므로 0을 반환하고 탐색 종료함.
```C++
int search(string str, int len)
{
    ++cnt;
    if (str == target) return 1;
    if (len == 5) return 0;
    for (char c: {'A', 'E', 'I', 'O', 'U'}) // char c: "AEIOU"로 구현하면 \0도 c에 포함
        if (search(str + c, len + 1))
            return 1;
    return 0;
}
```
탐색을 시작할 때 search("", 0)형식으로 빈 문자열을 전달하는데, 빈 문자열도 cnt에 포함되므로 정답이 되는 값은 cnt - 1이다.
<br>

