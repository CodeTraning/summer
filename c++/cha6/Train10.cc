#include <iostream>
using namespace std;

int iCount(initializer_list<int> il) {
    int count = 0;
    for (auto val : il)
        count += val;
    return count;
}

int main() {
    // 使用列表初始化的方式构建initializer_list<int>对象
    // 然后把它作为实参传递给函数iCount
    cout << "1, 6, 9的和:" << iCount({1, 6, 9}) << endl;
    cout << "10, 10, 10, 10, 10的和:" << iCount({10, 10, 10, 10, 10}) << endl;

    return 0;
}
