## 01. 피로도 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/87946

방문하는 순서의 순열을 완전탐색하는 알고리즘을 작성함.
방문 가능한 최대 던전의 개수가 8개 이므로 순열 완전탐색도 합리적인 시간안에 해결가능.

## 02. 기능개발 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/42586?language=cpp

진행도의 원소들을 진행속도 원소들에 대응되는 대로 업데이트
```
for (int i = 0; i < p.size(); ++i)
    p[i] += s[i];
```
왼쪽 끝에서부터 100이상이 되어 패스하는 작업물의 개수를 기록한 후 업데이트하기를 반복.

## 03. 다리를 지나는 트럭 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/42583?language=cpp

다리길이 개수만큼 0을 push한 queue로 최초의 다리를 표현.
현재 삭제하는 아이템이 0이 아니면 완전히 건너온 트럭 개수 하나 증가.
현재 다리에 트럭이 하나 더 올라갈 수 있으면 push(*t++).
1초에 하나씩 삭제, 삽입을 모든 트럭이 완전히 건너올때까지 반복