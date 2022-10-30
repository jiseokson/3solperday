## 00-01. 이동하기 ##
문제출처: https://www.acmicpc.net/problem/11048

``` C++
max_candy(i, j) = candy[i, j] + max(max_candy(i + dy, j + dx))
ans = max_candy(0, 0);
```

## 00-02. 미로탐색 ##
문제출처: https://www.acmicpc.net/problem/2178

bfs 연습