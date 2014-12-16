/// \file pipe2.c
/*
  ------------------------------------
  Create date : 2014-12-09 08:30
  Modified date: 2014-12-10 02:10
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
	int r_num1;
	int r_num2;
	int pipe_fd1[2];
	int pipe_fd2[2];
	char buf_r1[100],buf_w1[100];
	char buf_r2[100],buf_w2[100];

	memset(buf_r1,0,sizeof(buf_r1));
	memset(buf_r2,0,sizeof(buf_r2));

	if(pipe(pipe_fd1) < 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if(pipe(pipe_fd2) < 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	result = fork();
	if( result < 0) {
	
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(result == 0) {
		
		close(pipe_fd1[1]);
		if(r_num1 = read(pipe_fd1[0],buf_r1,100) > 0)
			printf("child process has read %d %s\n",r_num1,buf_r1);
		close(pipe_fd1[0]);


		close(pipe_fd2[0]);
		printf("please input the string:");
		scanf("%s",buf_w2);
		if(write(pipe_fd2[1],buf_w2,strlen(buf_w2)) != -1)
			printf("child process has written:%s to the pipe!\n",buf_w2);
			close(pipe_fd2[1]);

		exit(0);
	}
	else {

		close(pipe_fd1[0]);
		printf("please input the string:");
		scanf("%s",buf_w1);
		if(write(pipe_fd1[1],buf_w1,strlen(buf_w1)) != -1)
			printf("parent process has written:%s to the pipe!\n",buf_w1);
			close(pipe_fd1[1]);


		close(pipe_fd2[1]);
		if(r_num2 = read(pipe_fd2[0],buf_r2,100) > 0)
			printf("parent process has read %d %s\n",r_num2,buf_r2);
		close(pipe_fd2[0]);

			waitpid(result,NULL,0);
			exit(0);
	}

}
