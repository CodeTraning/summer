#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1;
    int num;
    char cont = 'y';
    while (cin >> num) {
        v1.push_back(num);
        cout << "您要继续吗(y or n)?" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
    }
    for (auto mem : v1)
        cout << mem << " ";
    cout << endl;
    return 0;
}
