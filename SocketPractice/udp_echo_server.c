#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_MAX (100)

int main(int argc, char *argv[])
{
	int serv_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	struct sockaddr_in serv_sockaddr;
	memset(&serv_sockaddr, 0x00, sizeof(serv_sockaddr));
	serv_sockaddr.sin_family = AF_INET;
	serv_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_sockaddr.sin_port = htons(1234);
	
	bind(serv_sock, (struct sockaddr *)&serv_sockaddr, sizeof(struct sockaddr));
	
	struct sockaddr_in cli_sockaddr;
	memset(&cli_sockaddr, 0x00, sizeof(cli_sockaddr));
	socklen_t cli_sockaddr_len = sizeof(cli_sockaddr);
	char buf_recv[BUF_MAX] = {0};
	memset(buf_recv, 0x00, sizeof(buf_recv));
	while(1)
	{
		int recv_len = recvfrom(serv_sock, buf_recv, BUF_MAX, 0, (struct sockaddr *)&cli_sockaddr, &cli_sockaddr_len);
		buf_recv[recv_len] = '\0';
		printf("Received form remote: %s\n", buf_recv);
		
		sendto(serv_sock, buf_recv, recv_len, 0, (struct sockaddr *)&cli_sockaddr, cli_sockaddr_len);
	}
	
	close(serv_sock);
	
	return (0);
}