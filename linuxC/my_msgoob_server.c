/// \file my_msgoob_server.c
/*
  ------------------------------------
  Create date : 2015-03-17 03:58
  Modified date: 2015-03-21 08:32
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	if(argc <= 2)
	{
		printf("ussage: %s ip_address port_number\n",basename(argv[0]));
		return 1;
	}
	const char *ip = argv[1];
	int port = atoi(argv[2]);						//atoi函数将字符串转换成整数

	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);		//用字符串表示ip
	address.sin_port = htons(port);					//转化为网络字节序

	int sock = socket(PF_INET, SOCK_STREAM, 0 );
	assert(sock >= 0);
	int ret = bind(sock, (struct sockaddr*)&address,sizeof(address));
	assert(ret != -1);
	ret = listen(sock,5);
	assert(ret != -1);

	struct sockaddr_in client;
	socklen_t client_addrlength = sizeof(client);
	int connfd = accept(sock, (struct sockaddr*)&client,&client_addrlength);
	if(connfd < 0)
	{
		printf("errno is %d\n",errno);
	}
	else
	{
		char buffer[BUF_SIZE];
		
		memset(buffer,'\0',BUF_SIZE);
		ret = recv(connfd,buffer,BUF_SIZE-1,0);
		printf("got %d bytes of normal data '%s'\n",ret,buffer);

		memset(buffer,'\0',BUF_SIZE);
		ret = recv(connfd, buffer,BUF_SIZE-1,MSG_OOB);
		printf("got %d bytes of oob data '%s'\n",ret,buffer);

		memset(buffer,'\0',BUF_SIZE);
		ret = recv(connfd,buffer,BUF_SIZE-1,0);
		printf("got %d bytes of normal data '%s'\n",ret,buffer);
	
		close(connfd);
	}


	close(sock);
	return 0;
}
