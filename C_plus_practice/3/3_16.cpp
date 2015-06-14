/// \file 3_16.cpp
/*
  ------------------------------------
  Create date : 2015-05-07 19:31
  Modified date: 2015-05-07 19:40
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v1;
	int x;
	for(int i =0;i<10;i++) {
		cin>>x;
		v1.push_back(x);
	}

	for(auto i : v1) {
		cout<<i;
	}
}

