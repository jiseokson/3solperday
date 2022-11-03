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

초기 값 k에 대해서 우박수열을 미리 계산해 두고 입력으로 받은 각 범위에 대해서 넓이를 구하는 방식으로 구현함. 최초의 구현에서 실패(seg fault)를 받았는데 stl containter size가 unsigned type으로 다뤄지는 사실을 인지하지 못해 발생했던 오류로 생각됨.
```C++
i < cols.size() + ran[1] - 1 // (x)
i - ran[1] < cols.size() - 1 // (o)
```

## 03. 연속 부분 수열 합의 개수 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/131701
<br>

