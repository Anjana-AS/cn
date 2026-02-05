//server
#include<stdio.h>
#include<string.h>
#include<unistd.h>	
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
int main()
{
int sockdes,newsock,fd,n;
char fname[25]="";
char fcontent[2000]="";
struct sockaddr_in server,client;
socklen_t c;
sockdes=socket(AF_INET,SOCK_DGRAM,0);
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
c=sizeof(client);
n=recvfrom(sockdes,fname,25,0,(struct sockaddr *)&client,&c);
fd=open(fname,O_RDONLY);
read(fd,fcontent,2000);
if(fd<0)
sendto(sockdes,"file not exit",14,0,(struct sockaddr *)&server,sizeof(client));
else
sendto(sockdes,fcontent,2000,0,(struct sockaddr *)&client,sizeof(server));
}
