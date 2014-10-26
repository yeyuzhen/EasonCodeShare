#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10

int SetFDNonblocking(int _fd)
{
	int oldFlags = fcntl(_fd, F_GETFL);
	if(-1 == oldFlags) return (-1);
	return fcntl(_fd, F_SETFL, oldFlags | O_NONBLOCK);
}

void AddFD(int _epollFD, int _fd, bool _enableET)
{
	epoll_event event;
	event.data.fd = _fd;
	event.events = EPOLLIN;
	if(_enableET)
	{
		event.events |= EPOLLET;
	}
	epoll_ctl(_epollFD, EPOLL_CTL_ADD, _fd, &event);
	SetFDNonblocking(_fd);
}

void ProcessLT(epoll_event *_events, int _number, int _epollFD, int _listenFD)
{
	char buffer[BUFFER_SIZE];
	for(int i = 0; i < _number; i++)
	{
		int fd = _events[i].data.fd;
		if(_listenFD == fd)
		{
			struct sockaddr_in clientAddr;
			bzero(&clientAddr, sizeof(clientAddr));
			socklen_t clientAddrLen = sizeof(clientAddr);
			int connFD = accept(_listenFD, (struct sockaddr*)&clientAddr, &clientAddrLen);
			AddFD(_epollFD, connFD, false);
		}
		else
		{
			if(_events[i].events & EPOLLIN)
			{
				printf("lt call once.\n");
				::memset(buffer, 0x00, sizeof(buffer));
				int recvLen = recv(fd, buffer, BUFFER_SIZE, 0);
				if(recv < 0)
				{
					close(fd);
					continue;
				}
				printf("recv %d byte data:%s\n", recvLen, buffer);
			}
			else
			{
				printf("Something else happened.\n");
			}
		}
	}
}

void ProcessET(epoll_event *_events, int _number, int _epollFD, int _listenFD)
{
	char buffer[BUFFER_SIZE];
	for(int i = 0; i < _number; i++)
	{
		int fd = _events[i].data.fd;
		if(_listenFD == fd)
		{
			struct sockaddr_in clientAddr;
			bzero(&clientAddr, sizeof(clientAddr));
			socklen_t clientAddrLen = sizeof(clientAddr);
			int connFD = accept(_listenFD, (struct sockaddr*)&clientAddr, &clientAddrLen);
			AddFD(_epollFD, connFD, true);
		}
		else if(_events[i].events & EPOLLIN)
		{
			printf("et call once.\n");
			while(1)
			{
				memset(buffer, 0x00, sizeof(buffer));
				int recvLen = recv(fd, buffer, BUFFER_SIZE - 1, 0);
				if(recvLen < 0)
				{
					if(EAGAIN == errno || EWOULDBLOCK == errno)
					{
						printf("Read later.\n");
						break;
					}
					close(fd);
					break;
				}
				else if(recvLen == 0)
				{
					close(fd);
				}
				else
				{
					printf("recv %d byte data:%s\n", recvLen, buffer);
				}
			}
		}
		else
		{
			printf("Something else happened.\n");
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc <= 3)
	{
		printf("Usage: %s ip_address port_number mode(LT/ET)\n", basename(argv[0]));
		return (1);
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);
	const char* mode = argv[3];
	printf("1\n");

	struct sockaddr_in listenAddr;
	bzero(&listenAddr, sizeof(listenAddr));
	listenAddr.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &listenAddr.sin_addr);
	listenAddr.sin_port = htons(port);
	printf("2\n");

	int listenFD = socket(PF_INET, SOCK_STREAM, 0);
	int option = 1;
	if(setsockopt(listenFD, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
	{
		printf("Set REUSEADDR fail.\n");
		return (1);
	}
	int ret = bind(listenFD, (struct sockaddr*)&listenAddr, sizeof(listenAddr));
	if(ret < 0)
	{
		printf("Bind fail.\n");
		return (1);
	}
	printf("3\n");
	ret = listen(listenFD, 5);
	if(ret < 0)
	{
		printf("Listen fail.\n");
		return (1);
	}
	printf("4\n");

	epoll_event events[MAX_EVENT_NUMBER];
	int epollFD = epoll_create(5);
	if(epollFD < 0)
	{
		printf("epoll_create fail.\n");
		return (1);
	}
	printf("5\n");
	AddFD(epollFD, listenFD, true);
	printf("6\n");

	while(1)
	{
		printf("7\n");
		int eventNum = epoll_wait(epollFD, events, MAX_EVENT_NUMBER, -1);
		printf("8\n");
		if(eventNum < 0)
		{
			printf("epoll_wait fail.\n");
			break;
		}

		printf("9\n");
		if(!strcmp(mode, "LT"))
		{
			printf("10\n");
			ProcessLT(events, eventNum, epollFD, listenFD);
			printf("11\n");
		}
		else
		{
			printf("12\n");
			ProcessET(events, eventNum, epollFD, listenFD);
			printf("13\n");
		}
	}

	printf("14\n");
	close(listenFD);
	close(epollFD);
	return (0);
}









