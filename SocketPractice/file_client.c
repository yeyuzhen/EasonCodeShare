#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define FILE_PATH "test.mp4"
#define BUF_MAX (1024)

int main(int argc, char *argv[])
{
	FILE *file = fopen(FILE_PATH, "wb");
	if (!file)
	{
		printf("Can not open file %s.\n", FILE_PATH);
		return (1);
	}
	
	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	struct sockaddr_in serv_sockaddr;
	memset(&serv_sockaddr, 0x00, sizeof(serv_sockaddr));
	serv_sockaddr.sin_family = AF_INET;
	serv_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_sockaddr.sin_port = htons(1234);
	
	connect(serv_sock, (struct sockaddr *)&serv_sockaddr, sizeof(struct sockaddr));
	
	printf("Start to receive file.\n");
	
	char buf_recv[BUF_MAX] = {0};
	memset(buf_recv, 0x00, sizeof(buf_recv));
	int read_len = 0;
	while((read_len = read(serv_sock, buf_recv, BUF_MAX)) > 0)
	{
		fwrite(buf_recv, 1, read_len, file);
		memset(buf_recv, 0x00, sizeof(buf_recv));
	}
	
	fclose(file);
	close(serv_sock);
	
	printf("Finished receive file.\n");
	
	return (0);
}