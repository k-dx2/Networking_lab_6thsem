#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#define max 100
# define SA struct sockaddr
void func(sockfd)
{
  char buff[max];
  int n;
  for (;;) {
       bzero(buff, sizeof(buff));
       printf("Enter the arithematic expression\n");
            n = 0;
       while ((buff[n++] = getchar()) != '\n')
           ;
       write(sockfd, buff, sizeof(buff));
       bzero(buff, sizeof(buff));
       read(sockfd, buff, sizeof(buff));
       printf("From Server : %s\n", buff);
       if ((strcmp(buff, "-1")) == 0)
      {
           printf("Client Exit...\n");
           break;
       }
   }
}

int main()
{
 int sockfd,len;
 struct sockaddr_in server;
 char buff[max];
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 if(sockfd<0)
 {
   printf("Socket creation failed\n");
   exit(0);
 }
 else
 printf("Socket created successfully\n");

server.sin_family=AF_INET;
server.sin_port=htons(50101);
server.sin_addr.s_addr=inet_addr("127.0.0.1");

if(connect(sockfd,(SA*)&server,sizeof(server))<0)
{
  printf("Connection with server failed\n");
  exit(0);
}
else
printf("Connected to server\n");

func(sockfd);
close(sockfd);

return 0;}
