## 01. 등대 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/133500

첫 번째 풀이: 시간초과  
간선 리스트 형태의 입력을 인접 리스트 형태로 변환함. 모든 등대가 켜져있는 등대와 적어도 하나 이상 연결될 때까지 켜져있는 등대와 연결되어있지 않은 등대가 가장 많이 연결된 순으로 등대를 하나씩 켜나감.
``` C++
// is_off(): 켜져있는 등대와 연결되지 않은 등대가 하나라도 존재하면 true
// on[]: 켜져있는 등대를 기록
// check[]: 자신이 켜져있는 등대이거나 켜져있는 등대와 연결된 경우에 기록
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
```
<br>

두 번째 구현: 통과
``` C++
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
```
등대들의 그래프는 트리를 이루므로 루트 노드로부터 켜야할 등대를 결정하는 dp알고리즘 작성.  
min_l(p, v, on): 부모가 p인 노드 v가 on일 때 자신과 모든 자식노드 중 켜야하는 최소 등대의 개수  
문제의 정답은 min_l(-1, 1, 0)과 min_l(-1, 1, 1)중 최소값.  
자신이 말단 노드라면 자신의 상태 on을 반환함. 자신이 말단 노드가 아니고 켜져있다면 자식 노드는 켜지거나 꺼지거나 상관없으므로 min(min_l(v, w, 1), min_l(v, w, 0))의 합계 반환. 자신이 말단 노드가 아니고 꺼져있다면 자식노드는 반드시 켜져있어야 하므로 min_l(v, w, 1)의 합계 반환.  
부모가 꺼져있다면 자신은 반드시 켜져야한다라는 탐욕법적인 가정을 했지만 이 가정이 최적부분구조를 이루는지에 대한 정확한 증명을 하지는 않음.