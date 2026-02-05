//client
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
int main()
{
int sockdes;
FILE * fd;
char s[100]="";
char s2[25]="";
char s1[2000]="";
struct  sockaddr_in client;
sockdes=socket (AF_INET,SOCK_STREAM,0);
if(sockdes==-1)
{
printf("cannot create socket");
}
client.sin_family=AF_INET;
client.sin_addr.s_addr=INADDR_ANY;
client.sin_port=htons(8888);
if(connect(sockdes,(struct sockaddr * ) &client,sizeof(client) )<0 )
{
printf("connection error");
return 1;
}
printf("\n enter the file name");
scanf("%s",s);
printf("\n nter new file name");
scanf("%s",s2);
write(sockdes,s,strlen(s));
fd=fopen(s2,"w");
while (read(sockdes,s1,2000)!=0)
{
fprintf(fd,"%s",s1);
}
printf("\n file recieved");
fclose(fd);
}
