#ifndef		_NET_H_
#define		_NET_H_

#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define	PORT	8080
#define	SA	struct sockaddr

int createNet(void);		
void closeNet(int connfd);

#endif		//_NET_H_
