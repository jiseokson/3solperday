#include <string>
#include <vector>

using namespace std;

string target;
int cnt = 0;

int search(string str, int len)
{
    ++cnt;
    if (str == target) return 1;
    if (len == 5) return 0;
    for (char c: {'A', 'E', 'I', 'O', 'U'}) // char c: "AEIOU"로 구현하면 \0도 c에 포함
        if (search(str + c, len + 1))
            return 1;
    return 0;
}

int solution(string word)
{
    target = word;
    search("", 0);
    return cnt - 1;
}