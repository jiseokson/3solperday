#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

vi get_pi(string p)
{
    vi pi(p.length(), 0);
    int j = 0;
    for (int i = 1; i < p.length(); ++i) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1]; // 완성된 범위의 실패함수를 이용하므로 정상
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vi kmp(string s, string p)
{
    vi ret;
    vi pi = get_pi(p);
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j]) {
            ++j;
            if (j == p.length()) {
                ret.push_back(i - j);
                // while (j > 0 && s[i] != p[j])
                j = pi[j - 1];
            }
        }
    }
    return ret;
}

int main(void)
{
    string s = "This is a string";
    string p = "is";
    vi ret = kmp(s, p);
    for(int i: ret) cout << s.substr(i, p.length()) << endl;
    return 0;
}