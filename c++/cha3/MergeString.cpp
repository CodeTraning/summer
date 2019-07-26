#include <iostream>
#include <string>

using namespace std;

int main() {
    char cont = 'y';
    string s, reslut;

    while (cin >> s) {
        reslut += s;
        cout << "是否继续（y or n）？"  << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "请输入下一个字符串：" << endl;
        else
            break;
    }

    cout << "拼接后的字符串：" << reslut << endl;
    return 0;
}
