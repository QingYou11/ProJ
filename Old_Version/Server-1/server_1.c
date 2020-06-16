//*****************************
//非并发服务器
//*****************************


#include<stdio.h>
#include<unistd.h>

#include"t_net.h"

int main(void){
	SA4 clie;
	
	int c_fd;

	int s_fd=socket_b(1024);
	if(-1==s_fd) return -1;
	
	listen(s_fd,5);

	while(1){
		socklen_t cli_len=sizeof(clie);
		c_fd=accept(s_fd,(SA *)&clie,&cli_len);
		if(-1==c_fd){
			perror("accept");
			return -1;
		}


		char IP[64];
		printf("%s\n",inet_ntop(AF_INET,&clie.sin_addr,IP,64));
		
		trans(c_fd);
		
		close(c_fd);
	}
	close(s_fd);
	return 0;
}
