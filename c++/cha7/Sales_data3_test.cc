#include <iostream>
#include "Sales_data3.h"
using namespace std;

int main() {
	Sales_data data1;
	Sales_data data2("1-22-333-4444");
	Sales_data data3("1-22-333-4444", 100, 100, 50);
	Sales_data data4(cin);

	cout << "书籍的销售情况:" << endl;
	cout << data1 << "\n" << data2 << "\n" << data3 << "\n" << data4 << "\n";

	return 0;
}