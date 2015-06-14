/// \file 3_10.cpp
/*
  ------------------------------------
  Create date : 2015-05-30 23:23
  Modified date: 2015-05-30 23:26
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>

using namespace std;

int main() {
	string str,str1="";
	cin>>str;
	for(auto &c : str)
		if(!ispunct(c))
			str1+=c;
	cout<<str1;
	return 0;
}
