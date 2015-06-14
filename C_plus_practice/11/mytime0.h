/// \file mytime0.h
/*
  ------------------------------------
  Create date : 2015-06-07 00:25
  Modified date: 2015-06-07 00:27
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#ifndef MYTIME0_H
#define MYTIME0_H

class Time {
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time Sum(const Time & t) const;
	void Show() const;

};

#endif
