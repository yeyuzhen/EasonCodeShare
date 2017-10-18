#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_MAX (100)


int main(int argc, char *argv[])
{
	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	struct sockaddr_in serv_sockaddr;
	memset(&serv_sockaddr, 0x00, sizeof(serv_sockaddr));
	serv_sockaddr.sin_family = AF_INET;
	serv_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_sockaddr.sin_port = htons(1234);
	
	bind(serv_sock, (struct sockaddr *)&serv_sockaddr, sizeof(struct sockaddr));
	
	listen(serv_sock, SOMAXCONN);
	
	struct sockaddr_in cli_sockaddr;
	memset(&cli_sockaddr, 0x00, sizeof(cli_sockaddr));
	
	socklen_t cli_sockaddr_len = sizeof(cli_sockaddr);
	int cli_sock = accept(serv_sock, (struct sockaddr *)&cli_sockaddr, &cli_sockaddr_len);
	
	char buf[BUF_MAX];
	memset(buf, 0x00, BUF_MAX);
	
	int len = read(cli_sock, buf, BUF_MAX);
	
	printf("received from client: %s\n", buf);
	
	write(cli_sock, buf, len);
	
	close(cli_sock);
	close(serv_sock);
	
	return (0);
}