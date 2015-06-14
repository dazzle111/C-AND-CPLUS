/// \file 3_6.cpp
/*
  ------------------------------------
  Create date : 2015-05-07 04:13
  Modified date: 2015-05-07 05:12
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>

using namespace std;
int main() {
	string str = "hellowrold";

	for(int i =0; i<str.size();i++) {
		str[i] = 'X';
	}
	cout<<str;
}
