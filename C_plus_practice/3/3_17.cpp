/// \file 3_17.cpp
/*
  ------------------------------------
  Create date : 2015-05-30 23:52
  Modified date: 2015-05-30 23:58
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string str1;
	vector<string> str;
	for(int i = 0 ;i < 10 ;i++) {
		cin>>str1;
		str.push_back(str1);
	}
	for(auto &i : str)
		for(auto &j : i)
			j = toupper(j);
	for(auto &i : str)
		cout<<i<<endl;
	
	return 0;
}
