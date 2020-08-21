
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <math.h>
#include <ctype.h>
#define SA struct sockaddr
#define max 100
char h[10];

int cal(char buff[])
{
int i=0,res=0,c=0;
int a=0,b=0;


// while(i!=strlen(buff))
//   {
//     if(isdigit(buff[i]))
//     {
//       c++;
//
//     }
//     else if(buff[i]=='\0')
//     {
//       return res;
//     }
//     else if(buff[i]=='+'||buff[]=='-'||buff[i]=='*'||buff[i]=='/')
//     {
//       i++;}

    // { int num=0;
    //   printf("the count %d \n",c);
    //   for(int j=c-1;j>=0;j--)
    //   {
    //     num=num+(buff[i-j-1]-'0')*pow(10,j);
    //   }
    //   printf("the digits%d\n",num);
    //
    //
    //   if(buff[i]=='+')
    //   res=res+num;
    //
    //   if(buff[i]=='-')
    //   res=res+num;
    //
    //   if(buff[i]=='*')
    //   res=res+num;
    //
    //   if(buff[i]=='/')
    //   res=res+num;
    //
    //   printf("the esult is %d\n",res);
    //

  //   c=0;
  //
  // }
  // i++;
  // }

}
void func(int sockfd)
{
    char buff[max];
    int n,res;

    for (;;) {
        bzero(buff, max);
        read(sockfd, buff, sizeof(buff));
        printf("From client: %s", buff);
        res=cal(buff);
        //printf("%d\n",res);
        sprintf(h,res);
        write(sockfd,h,sizeof(h));


        if (strcmp("-1", buff) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}
int main()
{
 int sockfd,connfd,len;
 struct sockaddr_in server,client;
 char buff_reply[max];
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
server.sin_addr.s_addr=INADDR_ANY;

if(bind(sockfd,(SA*)&server,sizeof(server))<0)
{
  printf("Server binding failed\n");
  exit(0);
}
else
printf("Server binded successfully\n");

listen(sockfd,5);


len=sizeof(client);
connfd=accept(sockfd,(SA*)&client,&len);
if(connfd<0)
{
  printf("server accept failed\n");
  exit(0);
}


func(connfd);
close(sockfd);



return 0;
}
