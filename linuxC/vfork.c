/// \file vfork.c
/*
  ------------------------------------
  Create date : 2014-10-22 03:37
  Modified date: 2014-10-22 03:59
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <apue.h>
#include <error.c>

int globvar = 6;

int main(void){
	int var;
	pid_t pid;

	var = 88;
	printf("brfore vfork\n");
	if ((pid = vfork()) < 0){
		err_sys("vfork error");
	}else if (pid == 0){
		globvar++;
		var++;
		_exit(0);
	}
	printf("pid = %ld, glob = %d, var = %d\n",(long)getpid(),globvar, var);
	exit(0);
}
