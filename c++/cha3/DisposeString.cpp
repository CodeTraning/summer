#include <iostream>
#include <string>

using namespace std;
/*
int main() {
    string s;
    cout << "请输入一个字符串，可以包含空格:" << endl;
    getline(cin ,s);
    for (char &c : s) {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}
*/

/*
int main() {
    string s;
    getline(cin, s);
    for (auto c : s) {
        if (!ispunct(c)) {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
*/

int main() {
    string s, result;
    getline(cin, s);
    for (decltype(s.size()) i = 0; i < s.size(); i++) {
        if (!ispunct(s[i])) {
            result += s[i];
        }
    }
    cout << result << endl;
    return 0;
}
