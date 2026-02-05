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
struct sockaddr_in server,client;
socklen_t c;
sockdes=socket(AF_INET,SOCK_DGRAM,0);
if(sockdes==-1)
{
printf("cannot create socket");
}
client.sin_family=AF_INET;
client.sin_addr.s_addr=INADDR_ANY;
client.sin_port=htons(8888);
printf("enter the file name");
scanf("%s",s);
printf("enter new file name");
scanf("%s",s2);
fd=fopen(s2,"w");
sendto(sockdes,s,2000,0,(struct sockaddr* ) &client,sizeof(server));
recvfrom(sockdes,s1,2000,0,(struct sockaddr* ) &server,&c);
fprintf(fd,"%s",s1);
fclose(fd);
}

