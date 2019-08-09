#include <iostream>
#include <string>
using namespace std;

// 返回值错误
bool str_subrange(const string &s1, const string &s2) {
    if (s1.size() == s2.size())
        return s1 == s2;

    auto size = (s1.size() < s2.size()) ? s1.size() : s2.size();

    for (decltype(size) i = 0; i != size; ++i) {
        if (s1[i] != s2[i])
            return;
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int e = str_subrange(s1, s2);
    return 0;
}
