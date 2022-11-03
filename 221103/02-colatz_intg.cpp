#include <vector>
#include <iostream>

using namespace std;
using vi = vector<int>;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vi cols;
    while (k != 1) {
        cols.push_back(k);
        if (k % 2 == 0) k /= 2;
        else k = 3 * k + 1;
    }
    cols.push_back(1);
    for (vi ran: ranges) {
        if (ran[0] - ran[1] > cols.size() - 1) {
            answer.push_back(-1.0);
            continue;
        }
        double ret = 0.0;
        for (int i = ran[0]; i - ran[1] < cols.size() - 1; ++i)
            ret += (double)cols[i] + cols[i + 1];
        answer.push_back(ret / 2.0);
    }
    return answer;
}