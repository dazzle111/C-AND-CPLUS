/// \file my_ll.c
/*
  ------------------------------------
  Create date : 2014-10-24 03:29
  Modified date: 2014-10-29 16:58
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>

void show(char *path);
void display(char *name);
void display_l(struct stat buf,char *name);

int main(int argc,char *argv[]){
	struct stat buf;
	char path[100]={0};

	if(argc == 1)
		show("./");
	else if(argc > 1){
		strcpy(path,argv[1]);
		if(stat(argv[1],&buf) == -1){
			perror("stat");
		}
		if(S_ISDIR(buf.st_mode)){
			if(path[strlen(argv[1])-1] != '/'){
				path[strlen(argv[1])] = '/';
				path[strlen(argv[1])+ 1] = '\0';
			}
			else
				path[strlen(argv[1])] = '\0';
			show(path);
		}
		else{
			display(path);
		}
	}
	return 0;

}

void show(char *path){
	DIR *dir;
	struct dirent *ptr;
	int count = 0;
	char filenames[256][100]={0};
	int i,j,len=strlen(path);

	dir = opendir(path);
	if(dir == NULL)
		perror("opendir");
	while((ptr = readdir(dir)) != NULL){
		count++;
	}
	closedir(dir);
	
	dir = opendir(path);
	for(i = 0 ; i < count; i++){
		ptr = readdir(dir);
		if(ptr == NULL)
			perror("readdir");
		strncpy(filenames[i],path,len);
		filenames[i][len] = '\0';
		strcat(filenames[i],ptr->d_name);
		filenames[i][len+strlen(ptr->d_name)] = '\0';
	}
	
	for(i = 0 ; i < count; i++)
		display(filenames[i]);
		
	closedir(dir);
	
}

void display(char *pathname){
	int i,j=0;
	struct stat buf;
	char name[31] = {0};
	
	for(i = 0 ;i < strlen(pathname);i++){
		if(pathname[i] == '/'){
			j = 0;
			memset(name,0,strlen(name))	;	
			continue;
		}
		name[j++] = pathname[i];
	}
	if(lstat(pathname,&buf) == -1){
		perror("lstat");
	}
	if(name[0] == '.')
		return;
	display_l(buf,name);
	printf("%s\n",name);
}

void display_l(struct stat buf,char *name){
	char buf_time[31]= {0};
	struct passwd *psd;
	struct group *grp;

	if(S_ISLNK(buf.st_mode)){
		printf("l");

	}else if (S_ISREG(buf.st_mode)){
		printf("-");
	
	}else if (S_ISDIR(buf.st_mode)){
		printf("d");

	}else if (S_ISCHR(buf.st_mode)){
		printf("c");
	
	}else if (S_ISBLK(buf.st_mode)){
		printf("b");
	
	}else if (S_ISFIFO(buf.st_mode)){
		printf("f");
	
	}else if (S_ISSOCK(buf.st_mode)){
		printf("s");
	}

	if(buf.st_mode & S_IRUSR) {
		printf("r");
	}else {
		printf("-");
	}
	if(buf.st_mode & S_IWUSR) {
		printf("w");
	}else {
		printf("-");
	}
	if(buf.st_mode & S_IXUSR) {
		printf("x");
	}else {
		printf("-");
	}

	if(buf.st_mode & S_IRGRP) {
		printf("r");
	}else {
		printf("-");
	}
	if(buf.st_mode & S_IWGRP) {
		printf("w");
	}else {
		printf("-");
	}
	if(buf.st_mode & S_IXGRP) {
		printf("x");
	}else {
		printf("-");
	}

	if(buf.st_mode & S_IROTH) {
		printf("r");
	}else {
		printf("-");
	}
	if(buf.st_mode & S_IWOTH) {
		printf("w");
	}else {
		printf("-");
	}
	if(buf.st_mode & S_IXOTH) {
		printf("x");
	}else {
		printf("-");
	}
	printf("  ");

	psd = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);
	printf("%4d ",buf.st_nlink);
	printf("%-8s",psd->pw_name);
	printf("%-8s",grp->gr_name);

	printf("%6d",buf.st_size);
	strcpy(buf_time,ctime(&buf.st_mtime));
	buf_time[strlen(buf_time) -1] = '\0';
	printf("  %s ",buf_time);

}
