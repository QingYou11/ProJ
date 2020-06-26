#include"net.h"

#include<stdio.h>
#include<stdlib.h>

int createNet(void){
	int sockfd,connfd,len;
	char IP[32];
	struct sockaddr_in servaddr,clie;

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORT);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd== -1){
		printf("套结字创建失败.\n");
		exit(0);
	}else
		printf("套结字已创建.\n");
	
	if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr))) != 0){
		printf("套结字与本地建立连接失败.\n");
		exit(0);
	}else
		printf("套结字与本地建立连接.\n");
	
	if((listen(sockfd,5)) != 0){
		printf("监听失败.\n");
		exit(0);
	}else
		printf("服务器正在监听.\n");

	len=sizeof(clie);
	connfd=accept(sockfd,(SA*)&clie,&len);
	if(connfd< 0){
		printf("服务器接收失败.\n");
		exit(0);
	}else
		printf("服务器与客户端 %s 建立连接.\n",\
				inet_ntop(AF_INET,&clie.sin_addr,IP,32));

	close(sockfd);
	
	return connfd;
}

void closeNet(connfd){
	close(connfd);
	printf("服务器已关闭....\n");
}
