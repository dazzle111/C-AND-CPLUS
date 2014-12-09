/// \file cp.c
/*
  ------------------------------------
  Create date : 2014-09-17 03:27
  Modified date: 2014-12-09 19:48
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

int main(int argc,char **argv){
	int fd_src,fd_des;
	char buf[128];
	int num;


	if((fd_src = open("/etc/passwd",O_RDONLY)) == -1){
		perror("open1");
		exit(EXIT_FAILURE);
	}

	if((fd_des = open("pass",O_CREAT|O_EXCL|O_WRONLY,0644)) == -1){
		perror("open2");
		exit(EXIT_FAILURE);
	}
	do{
		num = read(fd_src,buf,128);
		write(fd_des,buf,num);
	}while(num == 128);

	close(fd_src);
	close(fd_des);

	return  0;
}

