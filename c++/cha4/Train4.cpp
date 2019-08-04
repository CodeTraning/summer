#include <iostream>

using namespace std;

int main() {
    int x = 10, y = 20;
    bool someValue = true;
    someValue ? ++x, ++y : --x, --y;
    cout << x << endl << y << endl << someValue << endl;
    
    x = 10, y = 20;
    someValue = false;
    someValue ? ++x, ++y : --x, --y;
    cout << x << endl << y << endl << someValue << endl;

    return 0;
}
