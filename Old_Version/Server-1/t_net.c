#include<stdio.h>

#include<ctype.h>
#include<string.h>

#include"t_net.h"

int socket_b(int port){
	SA4 serv;
	serv.sin_family=AF_INET;
	serv.sin_port=htons(port);
	serv.sin_addr.s_addr=htonl(INADDR_ANY);
	

	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==s_fd){
		perror("socket");
		return -1;
	}
	int b=bind(s_fd,(SA *)&serv,sizeof(serv));
	if(-1==b){
		perror("bind");
		return -1;
	}
	return s_fd;
}

int trans(int c_fd){
	char buf[128];
	while(1){
		memset(buf,0,128);
		int r=read(c_fd,buf,128);
		int i;
		for(i=0;i<r;i++)
			buf[i]=toupper(buf[i]);
		write(c_fd,buf,r);
		if(strcmp(buf,"EXIT")==0) break;
	}
	return 0;
}
