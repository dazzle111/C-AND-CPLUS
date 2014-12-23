/// \file list_dir.c
/*
  ------------------------------------
  Create date : 2014-12-24 03:53
  Modified date: 2014-12-24 03:58
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int my_read(const char *path);

int main(int argc , char *argv[]){
	if( argc < 2 ) {
		printf("format error");
		exit(0);
	}

	if(my_read(argv[1]) < 0)
		exit(EXIT_FAILURE);
	return 0;
}

int my_read(const char *path) {
	DIR *dir;
	struct dirent *ptr;

	if((dir = opendir(path)) == NULL){
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	while((ptr = readdir(dir)) != NULL) {
		printf("file inode:%ld\t\t",ptr->d_ino);
		printf("file name:%s\n",ptr->d_name);
	}

	close(dir);
	return 0;
}
