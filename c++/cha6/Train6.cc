#include <iostream>
#include <string>
using namespace std;

bool HasUpper(const string& str) {
    for (auto c : str) {
        if (isupper(c)) 
            return true;
    }
    return false;
}

void ChangeToLower(string& str) {
    for (auto &c : str) {
        c = tolower(c);
    }
}

int main() {
    cout << "请输入一个字符串:" << endl;
    string s;
    cin >> s;
    if (HasUpper(s)) {
        ChangeToLower(s);
        cout << "转换后的字符串:" << endl << s << endl;
    } else {
        cout << "字符串不含大写字母，无需转换" << endl;
    }
    
    return 0;
}
