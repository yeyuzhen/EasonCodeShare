#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define FILE_PATH "/mnt/c/Users/yeyuzhen/Downloads/RG-NGFW.Basic.Function.mp4"
#define BUF_MAX (1024)

int main(int argc, char *argv[])
{
	
	FILE *file = fopen(FILE_PATH, "rb");
	if (!file)
	{
		printf("Cannot open file %s.\n", FILE_PATH);
		return (1);
	}
	
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
	socklen_t cli_socklen = sizeof(cli_sockaddr);
	
	int cli_sock = accept(serv_sock, (struct sockaddr *)&cli_sockaddr, &cli_socklen);
	
	printf("Start send file.\n");
	
	char buf_recv[BUF_MAX] = {0};
	memset(buf_recv, 0x00, BUF_MAX);
	int read_len = 0;
	while((read_len = fread(buf_recv, 1, BUF_MAX, file)) > 0)
	{
		write(cli_sock, buf_recv, read_len);
		memset(buf_recv, 0x00, BUF_MAX);
	}
	
	shutdown(cli_sock, SHUT_WR);
	read(cli_sock, buf_recv, BUF_MAX);
	
	fclose(file);
	close(cli_sock);
	close(serv_sock);
	
	printf("Send file finished.\n");
	
	return (0);
}













