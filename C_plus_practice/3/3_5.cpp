/// \file 3_5.cpp
/*
  ------------------------------------
  Create date : 2015-05-30 22:41
  Modified date: 2015-05-30 23:17
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>

using namespace std;

int main() {
	string str1,str2;

	cin>>str1>>str2;

	str1 = str1 + str2;
	for(auto &c : str1)
		c = toupper(c);
	cout<<str1;
	return 0;
}
