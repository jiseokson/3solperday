#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
using dqi = deque<int>;
using mii = map<int, int>;

int solution(vector<int> t) {
    int answer = 0;
    dqi lcnt(1, 1), rcnt(1, 1);
    mii lt, rt;
    lt.insert({t[0], 0});
    rt.insert({t.back(), 0});
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
    for (int i = 0; i < t.size() - 1; ++i)
        if (lcnt[i] == rcnt[i + 1])
            ++answer;
    return answer;
}