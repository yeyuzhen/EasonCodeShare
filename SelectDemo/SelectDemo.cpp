#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>  // System data types
#include <sys/socket.h>
#include <netinet/in.h>  // Internet address family
#include <arpa/inet.h>  // Definitions for internet operations
#include <libgen.h>

int main(int argc, char *argv[])
{
	if(argc <= 2)
	{
		printf("Usage: %s ip_address port_number\n", basename(argv[0]));
		return (1);
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);

	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	int opt = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
	ret = listen(listenfd, 5);

	struct sockaddr_in client_address;
	bzero(&client_address, sizeof(client_address));
	socklen_t client_addrlength = sizeof(client_address);
	int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);
	if(connfd < 0)
	{
		printf("errno is:%d\n", errno);
		return (1);
	}

	char buf[1024] = {0};
	fd_set read_fds;
	fd_set exception_fds;
	FD_ZERO(&read_fds);
	FD_ZERO(&exception_fds);

	while(1)
	{
		memset((void *)buf, 0x00, sizeof(buf));
		FD_SET(connfd, &read_fds);
		FD_SET(connfd, &exception_fds);
		ret = select(connfd + 1, &read_fds, NULL, &exception_fds, NULL);
		if(ret < 0)
		{
			printf("select failure!\n");
			break;
		}

		if(FD_ISSET(connfd, &exception_fds))
		{
			break;
		}

		if(FD_ISSET(connfd, &read_fds))
		{
			ret = recv(connfd, buf, sizeof(buf) - 1, 0);
			if(ret < 0)
			{
				printf("recv failure!\n");
				break;
			}

			printf("recv %d data:%s\n", ret, buf);
		}
	}

	close(connfd);
	close(listenfd);
	return (0);
}

