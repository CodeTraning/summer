#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec;
    int i;
    char cont = 'y';
    while (cin >> i) {
        ivec.push_back(i);

        cout << "您要继续吗(y or n)?" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
    }
    for (auto n : ivec)
        cout << "#" << n << endl;
    int count = 0, flag = 0;
    for (auto n : ivec) {
        if (0 == flag) {
            flag = 1;
            count = n;
        } else {
            cout << count + n << endl;
            flag = count = 0;
        }
    }
    // 如果元素数是奇数，单独处理最后一个元素
    if (ivec.size() % 2 != 0) 
        cout << count << endl;
    return 0;
}

