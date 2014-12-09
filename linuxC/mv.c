/// \file mv.c
/*
  ------------------------------------
  Create date : 2014-09-25 22:59
  Modified date: 2014-12-09 19:57
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc,char *argv[]){

	int fd_old,fd_new;
	int num=0;
	char buf[128];
	
	if(argc != 3)
	{
		printf("参数不够!格式:mv filename1 filename2\n");
		exit(1);
	}
	if((fd_old = open(argv[1],O_RDONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	if((fd_new = open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0644)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	do{
		num =read(fd_old,buf,128);
		write(fd_new,buf,num);
	}while(num == 128);

	close(fd_old);
	close(fd_new);

	if(remove(argv[1]) == -1){
		perror("remove");
		exit(EXIT_FAILURE);
	}

	return 0;
}
