## 01. 등대 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/133500

첫 번째 풀이: 시간초과  
간선 리스트 형태의 입력을 인접 리스트 형태로 변환을 함. 모든 등대가 켜져있는 등대와 적어도 하나 이상 연결될 때까지 켜져있는 등대와 연결되어있지 않은 등대가 가장 많이 연결된 순으로 등대를 하나씩 켜나감.
``` C++
// is_off: 켜져있는 등대와 연결되지 않은 등대가 하나라도 존재하면 true
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