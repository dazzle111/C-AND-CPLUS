/// \file file_stream.c
/*
  ------------------------------------
  Create date : 2014-09-17 03:13
  Modified date: 2014-09-17 03:23
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	int		fd;
	FILE	*stream;
	unlink("test.txt");
	fd = open("test.txt",O_CREAT|O_WRONLY,S_IREAD|S_IWRITE);
	stream = fdopen(fd,"w");
	
	if(stream == NULL)
		printf("fdopen null");
	else{
		fprintf(stream,"hello world\n");
		fclose(stream);
	}

	printf("the content of the test.txt is:\n");
	system("cat test.txt");
	return 0;

}
