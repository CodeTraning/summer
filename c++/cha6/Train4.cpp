#include <iostream>
using namespace std;

void myADD(double val1, double val2) {
    double res = val1 + val2;
    static unsigned iCnt = 0;
    ++iCnt;
    cout << val1 << "与" << val2 << "的求和结果:" << res << endl;
    cout << "myADD函数累计执行次数:" << iCnt << endl;
}

int main() {
    double num1, num2;
    cout << "请输入两个数:" << endl;
    while (cin >> num1 >> num2) {
        myADD(num1, num2);
    }
    return 0;
}
