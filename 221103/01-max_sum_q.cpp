#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;

ll sum(vi& a)
{
    ll ret = 0;
    for (int n: a) ret += (ll)n;
    return ret;
}

int solution(vector<int> ql, vector<int> qr) {
    int answer = 0;
    
    ll ls = sum(ql), rs = sum(qr);
    ql.insert(ql.end(), qr.begin(), qr.end());
    qr.insert(qr.end(), ql.begin(), ql.end());
    int l = 0, r = 0;
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
    
    return -1;
}