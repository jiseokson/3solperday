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
부모가 꺼져있다면 자신은 반드시 켜져야한다라는 탐욕법적인 가정을 했지만 이 가정이 최적부분구조를 이루는지에 대한 정확한 증명을 하지는 않음.(근데 아마 내가 맞을거임ㅋ아님말고)
<br>

문제를 풀면서 부족했던 점: 느낌은 알겠는데 마지막 순간까지 *정확한 부분문제 정의를 내리지 않음*. 첫 번째 풀이 시도에서도 문제의 그래프가 *트리를 이룬다는 사실을 알았지만 알고있기만 했음*.(해결에 어떤 식으로 이용할 수 있을지에 대해 고민하지 않음) 그래프+dp가 적용되는 문제 거의 처음 풀어봄.(*문제 많이 안풀어봄*)  

todo:
1. 부분문제 정의 똑바로 할 것
2. 알아낸 사실이 있으면 일단 써놓고 볼 것.
3. 문제 많이 풀어보기.

## 02. 택배배달 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/131704?language=cpp  
``` C++
for (auto i = order.begin(); i != order.end(); ++i) {
    while (b <= order.size() && (s.empty() || s.top() != *i))
        s.push(b++);
    if (s.top() == *i)
        s.pop(), ++answer;
    else
        break;
}
```
현재 주문이 스택의 top에 올 때까지 컨테이너에 있는 박스를 하나씩 push. top이 현재 주문과 같다면 다음 주문에 대한 작업으로 넘어가고 그렇지 않다면 종료.

## 03. 롤케이크 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/132265   
첫 번째 구현: 시간초과
``` C++
for (int i = 1; i < t.size(); ++i) {
    lcnt.push_back(lcnt.back());
    rcnt.push_front(rcnt.front());
    if (find(t.begin(), t.begin() + i, t[i]) == t.begin() + i)
        ++lcnt.back();
    if (find(t.rbegin(), t.rbegin() + i, *(t.rbegin() + i)) == t.rbegin() + i)
        ++rcnt.front();
}
```
lcnt[i]: t[0..i]에 존재하는 서로 다른 토핑의 종류  
rcnt[i]: t[i..]에 존재하는 서로 다른 토핑의 종류  
t의 크기가 1000000이므로 O(n^2)알고리즘으로도 충분히 동작할 것이라 예상하고 작성함.
<br>

두 번째 풀이: 통과
``` C++
for (int i = 1; i < t.size(); ++i) {
    lcnt.push_back(lcnt.back());
    rcnt.push_front(rcnt.front());
    if (lt.find(t[i]) == lt.end()) {
        ++lcnt.back();
        lt.insert({t[i], 0});
    }
    if (rt.find(*(t.rbegin() + i)) == rt.end()) {
        ++rcnt.front();
        rt.insert({*(t.rbegin() + i), 0});
    }
}
```
새로운 종류의 토핑이 추가될때마다 map에 저장함. 만약 현재 위치에 존재하는 토핑이 검색되지 않는다면 새로운 종류의 토핑이 발견된 것으로 간주함. 시간복잡도 O(nlog(n))으로 단축함.
<br>

다른 분 풀이:
```C++
map<int, int> l, r; // l[t] = cnt of t, r[t] = cnt of t
for (int n: t) ++r[n];
for (begin() <= i and i < end() - 1) {
    ++l[*i], --r[*i];
    if (r[*i] == 0) r.erase(*i);
    if (l.size() == r.size()) ++answer;
}
```
map[key] = val: 존재하지 않는 key라면 val 생성. 존재하지 않는 key로 대입하지 않고 참조만 한다면 기본값으로 val생성.
<br>

부족한 점: STL 자료구조 자연스럽게 활용하지 못함. 쉬운 방법으로 시간복잡도 줄일 수 있는데 안함.  
todo:
1. STL 기본 자료구조, 함수 등 사용법 숙지.
2. 시간복잡도 계산하는거 귀찮더라도 꼭 하기.