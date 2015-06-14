/// \file 2_42.cpp
/*
  ------------------------------------
  Create date : 2015-05-07 03:56
  Modified date: 2015-05-07 04:03
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>
#include "Sales_data.h"

using namespace std;

int main() {
	Sales_data data1,data2;
	
	double price;
	cin>>data1.bookNo>>data1.units_sold>>price;
	data1.revenue = data1.units_sold * price;
	cin>>data2.bookNo>>data2.units_sold>>price;
	data2.revenue = data2.units_sold * price;

	if(data1.bookNo == data2.bookNo) {
		double totalRevenue = data1.revenue + data2.revenue;
		unsigned totalCnt = data1.units_sold + data2.units_sold;

		cout<<data1.bookNo<<" "<<totalCnt<<" "<<totalRevenue<<" ";
		if(totalCnt != 0)
			std::cout<<totalRevenue/totalCnt<<endl;
		else
			cout<<"(no sales)"<<endl;
		return 0;
	}
	else {
		cerr<<"Data must refer to the same ISBN"<<endl;
		return -1;
	}
}
