#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<unsigned> ivec(10);
    auto it = ivec.begin();
    int iVal;
    cout << "请输入一组成绩（0~100）:" << endl;

    while (cin >> iVal) {
        if (iVal < 101)
            ++*(it + iVal / 10);
    }

    cout << "总计输入成绩的个数:" << ivec.size() << endl;
    cout << "各分数段的人数分布:" << endl;
    
    for (it = ivec.begin(); it != ivec.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
