#ifndef		_QNET_H_
#define		_QNET_H_

#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define	PORT	8080
#define	SA	struct sockaddr

int qNet(void);
void qcloseNet(int connfd);

#endif		//_QNET_H_
