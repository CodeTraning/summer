#include <iostream>
using namespace std;

// 该函数即不交换指针，也不交换指针所指内容
void SwapPointer1(int *p, int *q) {
    int *temp = q;
    p = q;
    q = temp;
}

// 该函数交换指针所指的内容
void SwapPointer2(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// 该函数交换指针本身的值，即交换指针所指的内存地址
void SwapPointer3(int *&p, int *&q) {
    int *temp = p; 
    p = q;
    q = temp;
}

int main() {
    int a = 1, b = 5;
    int *p = &a, *q = &b;
    cout << "SwapPointer1(int *p, int *q)" << endl;
    cout << "交换前:" << endl;
    cout << *p << " " << *q << endl << p << " " << q << endl;
    SwapPointer1(p, q);
    cout << "交换后:" << endl;
    cout << *p << " " << *q << endl << p << " " << q << endl;

    a = 1, b = 5;
    p = &a, q = &b;
    cout << "SwapPointer2(int *p, int *q)" << endl;
    cout << "交换前:" << endl;
    cout << *p << " " << *q << endl << p << " " << q << endl;
    SwapPointer2(p, q);
    cout << "交换后:" << endl;
    cout << *p << " " << *q << endl << p << " " << q << endl;

    a = 1, b = 5;
    p = &a, q = &b;
    cout << "SwapPointer3(int *&p, int *&q)" << endl;
    cout << "交换前:" << endl;
    cout << *p << " " << *q << endl << p << " " << q << endl;
    SwapPointer3(p, q);
    cout << "交换后:" << endl;
    cout << *p << " " << *q << endl << p << " " << q << endl;

    return 0;
}
