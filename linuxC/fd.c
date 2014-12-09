/// \file fd.c
/*
  ------------------------------------
  Create date : 2014-09-12 01:22
  Modified date: 2014-12-09 19:50
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fp1, fp2;
	printf("stdin is :\t%d\n",fileno(stdin));
	printf("stdout is :\t%d\n",fileno(stdout));
	printf("stderr is :\t%d\n",fileno(stderr));

	if((fp1 = open("fileop.c",O_WRONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	if((fp2 = open("fileno_exp.c",O_WRONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("fileop.c file is:\t%d\n",fp1);
	printf("fileno_exp.c is:\t%d\n",fp2);

	close(fp1);

/*当文件fileop.c关闭后，重新创建一个文件，查看其文件描述符是否顶替了fileop.c文件描述符的位置
	printf("after close fileop.c\n");
	if((fp1 = open("new_text.c",O_WRONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("new_text.c file is:\t%d\n",fp1);
	close(fp1);
*/

	close(fp2);
/*两个文件描述符交换测试
	if((fp1 = open("fileno_exp.c",O_WRONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	if((fp2 = open("fileop.c",O_WRONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("fileno_exp.c is:\t%d\n",fp1);
	printf("fileop.c is:\t%d\n",fp2);
	
	close(fp1);
	close(fp2);
*/
	return 0;

}
