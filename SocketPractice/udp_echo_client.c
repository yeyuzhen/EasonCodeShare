#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_MAX (100)

int main(int argc, char *argv[])
{
	int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	struct sockaddr_in serv_sockaddr;
	memset(&serv_sockaddr, 0x00, sizeof(serv_sockaddr));
	serv_sockaddr.sin_family = AF_INET;
	serv_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_sockaddr.sin_port = htons(1234);
	
	struct sockaddr_in remote_sockaddr;
	socklen_t remote_sockaddr_len = sizeof(remote_sockaddr);
	while(1)
	{
		char buf[BUF_MAX] = {0};
		memset(buf, 0x00, sizeof(buf));
		
		printf("Input a string: ");
		scanf("%s", buf);
		
		sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&serv_sockaddr, sizeof(serv_sockaddr));
		
		int recv_len = recvfrom(sock, buf, BUF_MAX, 0, (struct sockaddr *)&remote_sockaddr, &remote_sockaddr_len);
		buf[recv_len] = '\0';
		
		printf("Received from remote: %s\n", buf);
	}
	
	close(sock);
	
	return (0);
}