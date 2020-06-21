
int main(int argc,char *argv[]){
	int connfd;

	connfd=qNet();
	func(connfd);
	qcloseNet(connfd);

	return 0;
}
