/// \file test1.c
/*
  ------------------------------------
  Create date : 2014-12-09 08:30
  Modified date: 2014-12-09 08:45
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(){
	
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100],buf_w[100];

	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd) < 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	result = fork();
	if( result < 0) {
	
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(result == 0) {
		
		close(pipe_fd[1]);
		if(r_num = read(pipe_fd[0],buf_r,100) > 0)
			printf("child process has read %d %s\n",r_num,buf_r);

		close(pipe_fd[0]);
		exit(0);
	}
	else {

		close(pipe_fd[0]);
		printf("please input the string:");
		scanf("%s",buf_w);

		if(write(pipe_fd[1],buf_w,strlen(buf_w)) != -1)
			printf("parent process has written:%s to the pipe!\n",buf_w);
			close(pipe_fd[1]);
			waitpid(result,NULL,0);
			exit(0);
	}

}
