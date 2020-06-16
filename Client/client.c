#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define	PORT	8080
#define	MAX	256
#define	SA	struct sockaddr

void func(int sockfd){
	char *msg="this is a test ....\n";
	char buff[MAX];
	write(sockfd,msg,strlen(msg));
	int r=read(sockfd,buff,sizeof(buff));
	write(1,buff,r);
}

int main(){
	int sockfd;

	struct sockaddr_in servaddr;
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORT);
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");


	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd== -1){
		printf("套结字创建失败.\n");
		exit(0);
	}else
		printf("套结字创建成功.\n");

	if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr)) != 0){
		printf("客户端与服务器连接失败.\n");
		exit(0);
	}else
		printf("客户端与服务器连接成功.\n");

	func(sockfd);
	
	return 0;
}
