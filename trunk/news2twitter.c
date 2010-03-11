#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

main(){
	int sock;
	char buff[100];
	struct sockaddr_in servaddr;
	/* bzero((char *) &servaddr, sizeof(servaddr)); */
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.9.251");
	servaddr.sin_port = htons(119);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
		fprintf(stderr, "cannot connect\n");
		return (-1);
	}
	else printf("connected\n");
//	while(fgets(buff, 1, sock)
	read(sock, buff, sizeof(buff));
	printf("Server:\n%s", buff);
}

