#ifndef SALES_DATA2_H_INCLUDE
#define SALES_DATA2_H_INCLUDE

#include <iostream>
#include <string>
using namespace std;

class Sales_data {
private: // 定义私有数据成员
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;

public: // 定义公有函数成员
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data &rhs) {
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold)
					/ (rhs.units_sold + units_sold);
		units_sold += rhs.units_sold;
		if (sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;
	}
	Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
		Sales_data sum = lhs;
		sum.combine(rhs);
		return sum;
	}

	istream &read(istream &is, Sales_data &item) {
		is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
		return is;
	}

	ostream &print(ostream &os, const Sales_data &item) {
		os << item.isbn() << " " << item.units_sold << " " << item.sellingprice
	   	   << " " << item.saleprice << " " << item.discount;
		return os;
	}
};

#endif