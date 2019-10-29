#include <iostream>
#include <stdexcept>
using namespace std;

/*
 *strm::badbit 用来指出流已崩溃
 *strm::failbit 用来指出一个IO操作失败了
 *strm::eofbit 用来指出流到达了文件结束
 */

istream & f(istream & in) {
	int v;
	while (in >> v, !in.eof()) { // 直到遇到文件结束符才停止读取
		if (in.bad())
			throw runtime_error("IO流错误");
		if (in.fail()) {
			cerr << "数据错误，请重试:" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	in.clear();
	return in;
}

int main() {
	cout << "请输入一些整数:" << endl;
	f(cin);
	return 0;
}
