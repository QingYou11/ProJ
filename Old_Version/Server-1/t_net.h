#ifndef		T_NET_H_
#define		T_NET_H_

//文件的包含
#include<sys/socket.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

//类型的声明
typedef struct sockaddr_in SA4;
typedef struct sockaddr SA;

//函数的声明
int socket_b(int port);	//创建socket,绑定到本地地址

int trans(int c_fd);	//客户端的业务处理

#endif
