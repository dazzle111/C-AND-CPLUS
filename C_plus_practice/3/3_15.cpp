/// \file 3_15.cpp
/*
  ------------------------------------
  Create date : 2015-05-30 23:44
  Modified date: 2015-05-30 23:49
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<string> str;
	string str1;
	for(int i  = 0 ; i < 10 ;i++)  {
		cin>>str1;
		str.push_back(str1);
	}
	for(auto &i : str) 
		cout<<i<<endl;
	//for(auto i = str.begin();i != str.end(); i++)
	//	cout<<*i<<endl;
}
