#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 4, 0, 6};
    
    auto it1 = v1.cbegin(); // 定义v1的迭代器
    auto it2 = v2.cbegin(); // 定义v2的迭代器

    while (it1 != v1.cend() && it2 != v2.cend()) {
        if (*it1 != *it2) {
            cout << "v1和v2之间不存在前缀关系" << endl;
            break;
        }
        ++it1;
        ++it2;
    }
    if (it1 == v1.cend())
        cout << "v1是v2的前缀" << endl;
    if (it2 == v2.cend())
        cout << "v2是v1的前缀" << endl;

    return 0;
}
