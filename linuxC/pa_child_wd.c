/// \file pa_child_wd.c
/*
  ------------------------------------
  Create date : 2014-12-24 04:37
  Modified date: 2014-12-24 04:49
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
	int fd;
	pid_t pid;
	char buf[45];
	if((fd = open("code",O_CREAT | O_RDWR |O_TRUNC,S_IRWXU)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if(pid < 0 ){
		perror("fork");
		exit(0);
	}
	else if(pid == 0){
		printf("child process!\n");
		if(write(fd,"im a child process",19) < 0){
			perror("child error");
			exit(0);
		}
	}
	else if(pid > 0){
		sleep(6);
		printf("\nparent process\n");
		lseek(fd,0,SEEK_SET);
		if(read(fd,buf,19)<0){
			perror("read");
			exit(EXIT_FAILURE);
		}
		printf("\ncontent:%s\n",buf);
		close(fd);
	}
	return 0;
}
