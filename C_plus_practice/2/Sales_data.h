/// \file Sales_data.h
/*
  ------------------------------------
  Create date : 2015-05-07 03:52
  Modified date: 2015-05-07 03:53
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif
