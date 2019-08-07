#include <iostream>
using namespace std;

int fact(int val) {
    if (0 > val) return -1;

    int ret = 1;
    for (int i = 1; i != val + 1; ++i)
        ret *= i;
    return ret;
}

int main() {
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}
