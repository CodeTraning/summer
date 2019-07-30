#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    vector<string> v1;
    string s;
    char cont = 'y';
    while (cin >> s) {
        for (auto &c : s) 
            c = toupper(c);
        v1.push_back(s);
        cout << "您要继续吗(y or n)?" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
    }
    for (auto str : v1)
        cout << str << endl;
    return 0;
}
