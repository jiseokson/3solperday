#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using qi = queue<int>;

int solution(int bl, int weight, vector<int> tw) {
    int answer = 0;
    qi b;
    for (int i = 0; i < bl; ++i) b.push(0);
    int w = 0, cnt = 0;
    auto t = tw.begin();
    while (cnt < tw.size())
    {
        if (b.front() > 0)
        {
            ++cnt;
            w -= b.front();
        }
        b.pop();
        if (t != tw.end() && w + *t <= weight)
        {
            b.push(*t);
            w += *t;
            ++t;
        }
        else
            b.push(0);
        ++answer;
    }
    return answer;
}

int main(void)
{
    int tc = 3;
    int bl[3] = {2, 100, 100};
    int weight[3] = {10, 100, 100};
    vi tw[3] = {
        {7, 4, 5, 6},
        {10},
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}
    };
    for (int i = 0; i < tc; ++i)
    {
        cout << solution(bl[i], weight[i], tw[i]) << endl;
    }
    return 0;
}