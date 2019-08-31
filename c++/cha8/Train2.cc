#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream in("data.txt"); // 打开文件

	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	} 

	string line;
	vector<string> words;
	while (in >> line) { // 从文件中读取一行
		words.push_back(line);
	}

	in.close(); // 输入完毕，关闭文件

	vector<string>::const_iterator it = words.begin(); // 迭代器
	while (it != words.end()) { // 遍历vector
		cout << *it << endl;
		++it;
		cout << "##" << endl;
	}
	return 0;
}