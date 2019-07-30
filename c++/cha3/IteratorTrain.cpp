#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1的元素个数：" << v1.size() << endl;
    if (v1.size()) {
        cout << "v1的元素分别是：" << endl;
        for (auto e : v1) 
            cout << e << " ";
        cout << endl;
    }
    
    cout << "v2的元素个数：" << v2.size() << endl;
    if (v2.size()) {
        cout << "v2的元素分别是：" << endl;
        for (auto it = v2.begin(); it != v2.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    
    cout << "v6的元素个数：" << v6.size() << endl;
    if (v6.cbegin() != v6.cend()) {
        cout << "v6的元素分别是：" << endl;
        for (auto it = v6.begin(); it != v6.end() && !it->empty(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    cout << "v7的元素个数：" << v7.size() << endl;
    if (v7.cbegin() != v7.cend()) {
        cout << "v7的元素分别是：" << endl;
        for (auto it = v7.cbegin(); it != v7.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}
