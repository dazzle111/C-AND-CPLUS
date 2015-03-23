/// \file my_server.c
/*
  ------------------------------------
  Create date : 2015-03-17 03:07
  Modified date: 2015-03-17 03:20
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#define FALSE 0
#define TRUE 1
static int stop = FALSE;
static void handle_term(int sig)
{
	stop = TRUE;
}

int main(int argc, char *argv[])
{
	signal(SIGTERM,handle_term);
	if(argc <= 3)
	{
		printf("usage: %a ip_address port_number backlog\n",basename(argv[0]));
		return 1;
	}
	const char *ip = argv[1];
	int port = atoi(argv[2]);
	int backlog = atoi(argv[3]);

	int sock = socket(PF_INET,SOCK_STREAM,0);
	assert(sock >= 0);

	struct sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);

	int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
	assert(ret != 1);

	ret = listen(sock,backlog);
	assert(ret != 1);

	while(!stop)
	{
		sleep(1);
	}
	close(sock);
	return 0;


}
