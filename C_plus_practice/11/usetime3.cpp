/// \file usetime3.cpp
/*
  ------------------------------------
  Create date : 2015-06-07 01:03
  Modified date: 2015-06-07 01:05
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>
#include "mytime3.h"

int main() {
	using std::cout;
	using std::endl;
	Time aida(3,35);
	Time tosca(2,48);
	Time temp;

	cout<<"aida and tosca:\n";
	cout<<aida<<"; "<<tosca<<endl;
	temp = aida + tosca;
	cout<<"aida + tosca:"<<temp<<endl;
	temp = aida * 1.17;
	cout<<"aida * 1.17:"<<temp<<endl;
	cout<<"10 * tosca:"<<10 * tosca<<endl;

	return 0;

}
