//server
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
int main()
{
int sockdes,newsock,fd,c;
char fname[25]="";
char fcontent[2000]="";
struct sockaddr_in server,client;
sockdes=socket(AF_INET,SOCK_STREAM,0);
if(sockdes==-1)
{
printf("cannot create socket");
}
server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(8888);
if(bind(sockdes,(struct sockaddr * ) &server,sizeof(server) )<0 )
{
printf("bind failed");
return 1;
}
printf("bind done");
listen(sockdes,3);
printf(" waiting for incoming connection ");
c=sizeof(struct sockaddr_in );
if(newsock=accept(sockdes,(struct sockaddr* ) &client,(socklen_t*)&c) )
{printf("\n connection accepted");
recv(newsock,fname,25,0);
fd=open(fname,O_RDONLY);
read(fd,fcontent,2000);
if(fd<0)
write(newsock,"file not exit",14);
else
write(newsock,fcontent,strlen(fcontent));
}
}





