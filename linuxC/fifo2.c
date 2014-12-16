/// \file fifo2.c
/*
  ------------------------------------
  Create date : 2014-12-10 02:17
  Modified date: 2014-12-10 03:15
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <sys/types.h>
#include <sys/fcntl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

void main(){
	
	pid_t pid;
	char buffer1[80];
	char buffer2[80];
	int fd;

	unlink(FIFO1);
	mkfifo(FIFO1,0744);

	unlink(FIFO2);
	mkfifo(FIFO2,0744);
	if((pid = fork()) > 0) {
		
		char s[] = "hello!";
		fd = open(FIFO1,O_WRONLY);
		printf("this father write data is %s\n",s);
		write(fd,s,sizeof(s));
		close(fd);

		sleep(3);
		fd = open(FIFO2,O_RDONLY);
		read(fd,buffer1,80);
		printf("this is parent read data is:%s\n",buffer1);
		close(fd);
		printf("fathers pid is %d\n",getpid());
		exit(0);
	}
	else if (pid == 0) {
		
		char s[] = "hi!";
		sleep(2);
		fd = open(FIFO1,O_RDONLY);
		read(fd,buffer2,80);
		printf("this is child read data is:%s\n",buffer2);
		close(fd);

		fd = open(FIFO2,O_WRONLY);
		printf("this child write data is %s\n",s);
		write(fd,s,sizeof(s));
		close(fd);
		printf("child's pid is %d\n",getpid());
		exit(0);
	}
}
