/// \file usetime0.cpp
/*
  ------------------------------------
  Create date : 2015-06-07 00:31
  Modified date: 2015-06-07 00:34
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>
#include "mytime0.h"

int main() {
	using std::cout;
	using std::endl;

	Time coding(2,40);
	Time fixing(5,55);
	Time total;
	Time planning;

	cout<<"planning time =";
	planning.Show();
	cout<<endl;

	cout<<"coding time=";
	coding.Show();
	cout<<endl;

	cout<<"fixing time=";
	fixing.Show();
	cout<<endl;

	return 0;
}
