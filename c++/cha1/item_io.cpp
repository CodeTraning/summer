#include <iostream>
#include "Sales_item.h"

using namespace std;

int main() { 
    /*
     * 读取一组书籍销售记录
     * Sales_item book;
     * cin >> book;
     * cout << book << endl;
     */

    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (compareIsbn(item1, item2))
        cout << item1 + item2 << endl;
    else
        cout << "ISBN不同" << endl;
    return 0;
}
