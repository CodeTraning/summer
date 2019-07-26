#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    // 循环读取，每次输入读入一整行，直至文件结束或遇到异常输入
    //cout << "请输入您的字符串，可以包含空格：" << endl;
    
    /*使用getline一次读入一整行，遇到回车结束
     while (getline(cin, line)) {
        cout << line << endl;
     }
     */
    cout << "请输入您的单词，不可以包含空格：" << endl;
    while (cin >> line) {
        cout << line << endl;
    }

    return 0;
}
