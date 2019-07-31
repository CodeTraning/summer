#include <iostream>

using namespace std;

int main() {
    const int sz = 10;
    int a[sz], i = 0;
    for (i = 0; i < 10; i++)
        a[i] = i;
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    int *p = begin(a);
    while (p != end(a)) {
        *p = 0;
        p++;
    }
    for (auto val : a) 
        cout << val << " ";
    cout << endl;

    return 0;
}
