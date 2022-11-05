## 01. 소수 찾기 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/42839
<br>
``` C++
void find_prime(void)
{
    const int n = 10000000;
    is_prime = vi(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
}
```
에라토스테네스의 체 구현

## 02. 정수 삼각형 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/43105
<br>

## 03. 등굣길 ##
문제출처: https://school.programmers.co.kr/learn/courses/30/lessons/42898
<br>