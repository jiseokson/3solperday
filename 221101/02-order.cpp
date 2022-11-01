#include <vector>
#include <stack>
#include <iostream>

using namespace std;
using vi = vector<int>;
using si = stack<int>;

int solution(vector<int> order) {
    int answer = 0;
    int b = 1;
    si s;
    for (auto i = order.begin(); i != order.end(); ++i) {
        while (b <= order.size() && (s.empty() || s.top() != *i))
            s.push(b++);
        if (s.top() == *i)
            s.pop(), ++answer;
        else
            break;
    }
    return answer;
}

int main(void)
{
    const int tc = 2;
    vi order[tc] = {
        {4, 3, 1, 2, 5},
        {5, 4, 3, 2, 1}
    };
    for (int i = 0; i < tc; ++i)
        cout << solution(order[i]) << endl;
        
    return 0;
}