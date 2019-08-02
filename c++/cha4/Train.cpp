#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> vec;
    srand((unsigned) time (NULL));
    cout << "系统自动为向量生成一组元素......" << endl;
    for (int i = 0; i != 10; i++)
        vec.push_back(rand() % 100);
    cout << "生成的向量数据是：" << endl;
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    cout << "验证添加的括号是否正确：" << endl;
    cout << "*vec.begin():" << *vec.begin() << endl;
    cout << "*(vec.begin()):" << *(vec.begin()) << endl;
    cout << "*vec.begin()+1:" << *vec.begin()+1 << endl;
    cout << "(*(vec.begin()))+1:" << (*(vec.begin()))+1 << endl;
    cout << "*(vec.begin()+1):" << *(vec.begin()+1) << endl;
    return 0;
}
