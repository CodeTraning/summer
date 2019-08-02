#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> vec;
    const int sz = 10;
    srand((unsigned) time (NULL));
    cout << "数组的初始值：" << endl;
    for (int i = 0; i != sz; ++i) {
        vec.push_back(rand() % 100);
        cout << vec[i] << " ";
    }
    cout << endl;
    for (auto &val : vec) 
        val = (val % 2 == 0) ? val : val * 2;
    cout << "调整后的数组值：" << endl;
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
