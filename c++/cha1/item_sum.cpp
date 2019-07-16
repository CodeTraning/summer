#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() {
    Sales_item item;
    if (cin >> item) {
        int sum = 1;
        Sales_item book;
        while (cin >> book) {
            if (item.isbn() == book.isbn())
                ++sum;
            else {
                cout << item.isbn() << "消费记录：" << sum << endl;
                item = book;
                sum = 1;
            }
        }
        cout << item.isbn() << "消费记录：" << sum << endl;
    } else {
        cout << "没有数据" << endl;
        return -1;
    }
    return 0;
}
