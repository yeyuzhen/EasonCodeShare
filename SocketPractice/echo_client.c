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
	
	connect(serv_sock, (struct sockaddr *)&serv_sockaddr, sizeof(struct sockaddr));
	
	char buf_send[BUF_MAX];
	memset(buf_send, 0x00, BUF_MAX);
	
	scanf("%s", buf_send);
	
	write(serv_sock, buf_send, strlen(buf_send));
	printf("Send to server: %s\n", buf_send);
	
	char buf_recv[BUF_MAX];
	memset(buf_recv, 0x00, BUF_MAX);
	
	read(serv_sock, buf_recv, BUF_MAX);
	printf("Received from server: %s\n", buf_recv);
	
	close(serv_sock);
	
	return (0);
}