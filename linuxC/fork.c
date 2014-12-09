/// \file fork.c
/*
  ------------------------------------
  Create date : 2014-09-26 01:12
  Modified date: 2014-10-22 04:08
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <apue.h>
#include <error.c>
int globvar = 6;
char buf[] = "a write to stout\n";

int 
main(void){
	int		var;
	pid_t	pid;

	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		err_sys("write error");
	printf("before fock\n");

	if((pid = fork()) < 0){
		err_sys("fork error");
	}else if (pid == 0) {
		globvar++;
		var++;
	} else {
		sleep(2);
	}

	printf("pid = %ld, glob = %d, var = %d\n",(long)getpid(), globvar, var);
	exit(0);
}
