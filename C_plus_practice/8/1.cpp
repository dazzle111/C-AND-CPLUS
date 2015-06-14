/// \file 1.cpp
/*
  ------------------------------------
  Create date : 2015-05-28 17:38
  Modified date: 2015-05-28 19:34
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <iostream>

using namespace std;

double besty(int) ;
double pam(int) ;

void estimate(int lines, double (*pf)(int)) ;

int main() {
	using namespace std;

	int code ;
	cout<<"How many lines of code do you need?"<<endl;
	cin>>code;
	cout<<"heres pan' estimate"<<endl;
	estimate(code , pam);
	cout<<"heres besty' estimate"<<endl;
	estimate(code , besty);

	return 0;
}

double besty(int lns) {
	return 0.05 * lns;
}

double pam(int lns) {
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int)) {
	using namespace std;

	cout<<lines<<"line will take ";
	cout<<(*pf)(lines)<<" hours"<<endl;
}
