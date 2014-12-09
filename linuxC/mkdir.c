/// \file mkdir.c
/*
  ------------------------------------
  Create date : 2014-09-25 23:22
  Modified date: 2014-12-09 19:56
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argv,char **argc){
	if(argv != 2){
		printf("格式不对！");
		exit(EXIT_FAILURE);
	}
	//权限：mode&~umask&0777
	if(mkdir(argc[1],0111) == -1){
		perror("mkdir");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
