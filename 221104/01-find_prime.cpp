#include <vector>
#include <map>

using namespace std;
using vi = vector<int>;
using mii = map<int, int>;

vi ns;
vi check;
mii pcnt;

int is_prime(int n)
{
    if (n < 2) return 0;
    if (n == 2) return 1;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return 0;
    return 1;
}

void search(int n, int len)
{
    if (is_prime(n)) ++pcnt[n];
    if (len == ns.size()) return;
    for (int i = 0; i < ns.size(); ++i) {
        if (check[i]) continue;
        check[i] = 1;
        search(n * 10 + ns[i], len + 1);
        check[i] = 0;
    }
}

int solution(string numbers)
{
    check = vi(numbers.length(), 0);
    for (char c: numbers) ns.push_back(c - '0');
    search(0, 0);
    return pcnt.size();
}