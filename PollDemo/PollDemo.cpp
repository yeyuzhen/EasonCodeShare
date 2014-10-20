#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <libgen.h>  // basename

#include <poll.h>

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
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
	{
		printf("setsockopt error.\n");
		return (1);
	}
	int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
	ret = listen(listenfd, 5);

	struct sockaddr_in client_address;
	bzero(&client_address, sizeof(client_address));
	socklen_t client_addrlength = sizeof(client_address);

	int clientfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);

	struct pollfd fds[8];
	::memset((void *)fds, 0x00, sizeof(fds));
	for(int i = 0; i < 8; i++)
	{
		fds[i].fd = -1;
	}

	fds[0].fd = clientfd;
	fds[0].events = POLLIN;
	char buf[1024] = {0};

	while(1)
	{
		::memset((void *)buf, 0x00, sizeof(buf));
		ret = poll(fds, 8, -1);
		if(ret < 0)
		{
			printf("poll error.\n");
			return (1);
		}

		if(fds[0].revents & POLLIN)
		{
			ret = recv(fds[0].fd, buf, 1024 - 1, 0);
			printf("recv data: %s\n", buf);
		}
	}

	close(clientfd);
	close(listenfd);
	return (0);
}
