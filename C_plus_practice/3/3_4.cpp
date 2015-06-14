/// \file 3_4.cpp
/*
  ------------------------------------
  Create date : 2015-05-30 22:36
  Modified date: 2015-05-30 22:40
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>

using namespace std;

const string &stringBig(const string &str1, const string &str2) {
	return str1>str2?str1:str2;
}
const int stringLength(const string &str1, const string &str2) {
	return str1.length()>str2.length()?str1.length():str2.length();
}
int main() {
	string str1,str2;
	cin>>str1>>str2;
	cout<<"the bigger string is: "<<stringBig(str1,str2)<<endl;
	cout<<"the longer string is: "<<stringLength(str1,str2)<<endl;

	return 0;
}
