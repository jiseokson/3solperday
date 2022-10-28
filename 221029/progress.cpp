#include <iostream>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

void update(vi& p, vi& s)
{
    for (int i = 0; i < p.size(); ++i)
        p[i] += s[i];
}

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    int i = 0;
    while (i < p.size())
    {
        int cnt = 0;
        while (i < p.size() && p[i] >= 100)
            ++i, ++cnt;
        if (cnt > 0)
            answer.push_back(cnt);
        while (i < p.size() && p[i] < 100)
            update(p, s);
    }
    return answer;
}

int main(void)
{
    const int tc = 2;
    vi p[tc] = {
        {93, 30, 55},
        {95, 90, 99, 99, 80, 99}
    };
    vi s[tc] = {
        {1, 30, 5},
        {1, 1, 1, 1, 1, 1}
    };
    for (int i = 0; i < tc; ++i)
    {
        vi answer = solution(p[i], s[i]);
        for (int j = 0; j < answer.size(); ++j)
            cout << answer[j] << ' ';
        cout << endl;
    }
    return 0;
}