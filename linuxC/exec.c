/// \file test1.c
/*
  ------------------------------------
  Create date : 2014-12-24 23:30
  Modified date: 2014-12-24 23:44
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
main(){
	int flag;
	pid_t pid;
	char *const argv[]={"%U","--user-data-dir=/usr/lib/firefox",NULL};
	if((pid = fork()) == 0) {
		printf("in child process 1....\n");
		//flag = execvp("./hello",NULL);
		char *envp[] = {"PATH=.",NULL};
		flag = execv("hello",NULL);
		if(flag == -1)
			printf("exec error!\n");
	}
	if((pid = fork()) == 0){
		printf("in child process 2....\n");
		flag = execlp("ls","al",NULL);
		if(flag == -1)
			printf("exec error\n");
	}

	if((pid = fork()) == 0){
		printf("in child process 3....\n");
		flag  = execv("/usr/bin/firefox",argv);
		if(flag == -1)
			printf("exec error\n");
	}

	printf("in parent process...\n");
	return 0;
}
