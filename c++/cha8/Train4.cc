#include <iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

/*
 *argc是传入参数的个数，”传入的参数“加上可执行文件的文件名；
 *argv[]存放的是传给main函数的参数，
 *argv是字符串数组，所以下标从0开始，第一个存放的是可执行程序的文件名字，然后依次存放传入的参数；
 */
int main(int argc, char *argv[]) {
	if (argc != 3) {
		cerr << "请给出文件名" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	// ofstream out(argv[2]);
	ofstream out(argv[2], ofstream::app);
	if (!out) {
		cerr << "无法打开输入文件!" << endl;
		return -1;
	}

	cout << "$$" << endl;

	Sales_data total;
	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	} else {
		cerr << "没有数据" << endl;
	}

	return 0;
}