#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(){
int sockdes,newsock,c;
struct sockaddr_in server,client;
char msg[2000],replay[2000];
sockdes=socket(AF_INET,SOCK_STREAM,0);
if(sockdes==-1)
{
printf("cannot create socket");
}
server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(8888);
if(bind(sockdes,(struct sockaddr*)&server,sizeof(server))<0)
{
printf("bind failed");
return 1;
}
printf("\n bind done");
listen(sockdes,3);
printf("\n waiting for incoming connection");
c=sizeof(struct sockaddr_in);
if(newsock=accept(sockdes,(struct sockaddr*)
&client,(socklen_t*)&c))
{
printf("\n connection accepted");
while(1)
{
recv(newsock,replay,2000,0);
printf("\n from client");
puts(replay);
printf("\n to client");
scanf("%s",msg);
send(newsock,msg,2000,0);
}}
if(newsock==-1)
{
perror("\n accept failed");
return 1;
}
return 0;
}
