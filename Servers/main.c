
int main(int argc,char *argv[]){
	int connfd;

	connfd=createNet();
	func(connfd);
	closeNet(connfd);

	return 0;
}
