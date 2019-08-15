#include <iostream>
using namespace std;

class Person {
    private:
        string strName; // 姓名
        string strAddress; // 地址
    public:
        Person() = default;
        Person(const string &name, const string &add) {
            strName = name;
            strAddress = add;
        }
    Person(std::istream &is) { is >> *this; }
    public:
        string getName() const { return strName; } // 返回姓名
        string getAddress() const { return strAddress; } // 返回地址
        /*
         *上述两个函数应该被定义为常量成员函数
         *因为不论返回姓名还是返回地址，
         *在函数体内都只是读取数据成员的值，
         *而不会做任何改变
         */
        istream &read(istream &is, Person &per) {
            is >> per.strName >> per.strAddress;
            return is;
        }
        ostream &print(ostream &os, const Person &per) {
            os << per.getName() << per.getAddress;
            return os;
        }

};
