/// \file endian_judge.c
/*
  ------------------------------------
  Create date : 2015-03-17 02:50
  Modified date: 2015-03-17 02:53
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>

void byteorder() 
{	
	union
	{
		short value;
		char union_bytes[sizeof(short)];
	}test;
	test.value = 0x0102;
	if((test.union_bytes[0] == 1) && (test.union_bytes[1] == 2))
	{
		printf("big endian\n");
	}
	else if((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1))
	{
		printf("little endian\n");
	}
	else
	{
		printf("unknown...\n");
	}
}
