#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in server_address;
	memset(&server_address, 0x00, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(1234);
	
	connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
	
	char buffer[40];
	memset(buffer, 0x00, sizeof(buffer));
	
	read(sock, buffer, sizeof(buffer) - 1);
	
	printf("Receive form server: %s\n", buffer);
	
	close(sock);
	
	return (0);
}