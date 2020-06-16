#include"convert_func.h"

void func(int connfd){
	char buff[MAX];
	int r=read(connfd,buff,sizeof(buff));
	int i;
	for(i=0;i<r;i++)
		buff[i]=toupper(buff[i]);
	write(connfd,buff,r);
}
