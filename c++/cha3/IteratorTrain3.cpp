#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> ivec;

    srand((unsigned)time(NULL)); // 生成随机数种子    
    for (int i = 0; i < 10; i++) {
        ivec.push_back( rand() % 1000 );
    }

    cout << "随机生成的10个数据：" << endl;
    for (auto it = ivec.cbegin(); it != ivec.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "翻倍后的10个数字：" << endl;
    for (auto it = ivec.begin(); it != ivec.end(); it++) {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
