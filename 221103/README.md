## 01. 두 큐의 합 같게 만들기 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/118667
<br>

```C++
for (int i = 0; i < ql.size() * 2; ++i) {
    if (ls > rs) {
        ls -= ql[l];
        rs += ql[l];
        ++l;
        ++answer;
    } else if (ls < rs) {
        rs -= qr[r];
        ls += qr[r];
        ++r;
        ++answer;
    } else {
        return answer;
    }
}
```
두 큐의 원소들의 합을 비교했을때 큰 쪽에 있는 원소 하나를 다른 쪽으로 이동하는 탐욕적인 방법을 구현.

## 02. 우박수열 정적분 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/134239
<br>

초기 값 k에 대해서 우박수열을 미리 계산해 두고 입력으로 받은 각 범위에 대해서 넓이를 구하는 방식으로 구현함. 최초의 구현에서 실패(seg fault)를 받았는데 stl container size가 unsigned type으로 다뤄지는 사실을 인지하지 못해 발생했던 오류로 생각됨.
```C++
i < cols.size() + ran[1] - 1 // (x)
i - ran[1] < cols.size() - 1 // (o)
```

## 03. 연속 부분 수열 합의 개수 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/131701
<br>

```C++
int rs(int lo, int hi)
{
    if (lo > hi)
        return rs(0, hi) + rs(lo, ps.size() - 1);
    if (lo == 0)
        return ps[hi];
    else return ps[hi] - ps[lo - 1];
}

solve()
{
    for (int lo = 0; lo < e.size(); ++lo)
        for (int hi = 0; hi < e.size(); ++hi)
            ++sums[rs(lo, hi)];
    answer = sums.size();
}
```
rs: 원형 리스트에서 [lo..hi]범위 원소들의 합. lo > hi인 경우에는 [..hi] + [lo..]범위 원소들의 합.  
sums는 map<int, int>이고, 존재하는 모든 종류의 합과 그 합의 개수를 기록. 시간복잡도 O(n^2*log(n))의 알고리즘이므로 e.size() <= 1000에서 빠른 시간에 동작.
<br>

원형 구조의 자료가 주어지는 경우 경계에 대한 조건이 없어 문제를 풀 때 항상 까다롭게 느꼈다. 다른 분의 풀이를 보자.
```C++
const int len = e.size();
e.insert(e.end(), e.begin(), e.end());
for (int start = 0; i < len; ++i)
    for (int l = 0; l < len; ++ l)
        ++sums[rs(start, start + l)];
```
원형 리스트에서는 연속인 부분 수열이 선형 리스트에서는 경계에 걸치는 경우가 있어 까다로웠다. 주어진 리스트를 2배하여 선형 리스트에서 합을 구하는 것과 동일한 방법으로 원형 리스트에 존재하는 모든 연속 부분 수열의 합을 구할 수 있다.
<br>

## 04. 전력망을 둘로 나누기 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/86971
<br>

```C++
int min_diff(int p, int v)
{
    if (g[v].size() == 1 && g[v][0] == p) return abs(cnt(-1, 1) - 2 * 1);
    int ret = abs(cnt(-1, 1) - 2 * cnt(p, v));
    for (int w: g[v]) {
        if (w == p) continue;
        ret = min(ret, min_diff(v, w));
    }
    return ret;
}
```
주어진 그래프는 트리를 이루므로 1을 루트노드로 임의지정. 루트부터 시작해 하위의 모든 노드들을 순회하며 현재 위치와 부모 노드 사이의 간선을 끊을 경우 두 그래프 사이의 노드 개수 차이가 최소값이 되는 경우를 완전탐색함.