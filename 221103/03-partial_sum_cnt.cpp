#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using mii = map<int, int>;

vi ps;
mii sums;

int rs(int lo, int hi)
{
    if (lo > hi)
        return rs(0, hi) + rs(lo, ps.size() - 1);
    if (lo == 0)
        return ps[hi];
    else return ps[hi] - ps[lo - 1];
}

int solution(vector<int> e) {
    int answer = 0;
    ps = vi(e.size(), 0);
    ps[0] = e[0];
    for (int i = 1; i < e.size(); ++i)
        ps[i] = ps[i - 1] + e[i];
    for (int lo = 0; lo < e.size(); ++lo)
        for (int hi = 0; hi < e.size(); ++hi)
            ++sums[rs(lo, hi)];
    return answer = sums.size();
}