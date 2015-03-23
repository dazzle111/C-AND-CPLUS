/// \file my_err_connect.c
/*
  ------------------------------------
  Create date : 2015-03-17 03:27
  Modified date: 2015-03-17 03:48
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

int main(int argc, char *argv[])
{
	if(argc <= 2)
	{
		printf("usage: %s ip_addrrss port_numbers\n",basename(argv[0]));
		return 1;
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);		//将port转换为IPV4的端口字符串
	address.sin_port = htons(port);

	int sock = socket(PF_INET, SOCK_STREAM,0);
	assert(sock >= 0);

	int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
	assert(ret != -1);

	ret = listen(sock, 5);
	sleep(20);
	struct sockaddr_in client;
	socklen_t client_addrlength = sizeof(client);
	int connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);

	if(connfd < 0)
	{
		printf("errno is %d\n",errno);
	}
	else
	{
		char remote[INET_ADDRSTRLEN];
		printf("connected with ip: %s and port: %d\n",inet_ntop(AF_INET,&client.sin_addr, remote, INET_ADDRSTRLEN),ntohs(client.sin_port));
		close(connfd);
	}

	close(sock);
	return 0;
}
