#include <iostream>
using namespace std;

void mySWAP(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main() {
    int a = 2, b = 8;
    int *x = &a, *y = &b;
    cout << "交换前:" << a << " " << b << endl;
    mySWAP(x, y);
    cout << "交换后:" << a << " " << b << endl;
    return 0;
}
