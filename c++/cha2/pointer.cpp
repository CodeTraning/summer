#include <iostream>

using namespace std;

int main() {
    int ival = 2, ival2 = 4;
    int *pi = &ival;
    cout << *pi << " " << pi << endl;
    pi = &ival2;
    cout << *pi << " " << pi << endl;
    *pi = 6;
    cout << *pi << " " << pi << endl;
    ival2 = 8;
    cout << *pi << " " << pi << endl;
    return 0;
}

