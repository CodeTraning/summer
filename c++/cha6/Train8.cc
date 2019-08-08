#include <iostream>
using namespace std;

// 参数是常量整型指针
void print1(const int *p) {
    cout << *p << endl;
}

void print2(const int *p, const int size) {
    int i = 0;
    while (i != size) {
        cout << *p++ << endl;
        ++i;
    }
}

void print3(const int *b, const int *e) {
    for (auto p = b; p != e; ++p)
        cout << *p << endl;
}

int main() {
    int i = 0, j[2] = {1, 2};
    print1(&i);
    print1(j);

    print2(&i, 1);
    print2(j, sizeof(j) / sizeof(*j)); // 计算得到数组j的容量

    auto b = begin(j);
    auto e = end(j);
    print3(b, e);

    return 0;
}
