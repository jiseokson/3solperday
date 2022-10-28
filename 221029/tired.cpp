#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int solve(vvi& d, vi& perm, int k)
{
    int ret = 0;
    for (; ret < perm.size(); ++ret)
    {
        if (d[perm[ret]][0] > k)
            break;
        k -= d[perm[ret]][1];
    }
    return ret;
}

int solution(int k, vector<vector<int>> d) {
    int answer = -1;
    vi perm(d.size());
    for (int i = 0; i < d.size(); ++i)
        perm[i] = i;
    do
    {
        answer = max(answer, solve(d, perm, k));
    } while (next_permutation(perm.begin(), perm.end()));
    return answer;
}

int main(void)
{
    int k = 80;
    vvi d = {{80, 20}, {50, 40}, {30, 10}};
    cout << solution(k, d);
    return 0;
}