
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 100
#define PORT 50101
#define SA struct sockaddr


void palindrome(char buff[])
{
  int i=0,j=strlen(buff)-2,f=0;
  // printf("The length of string is %d\n",j);
  while(i<=j)
  {
    if(buff[i]!=buff[j])
    {
      f=1;
      break;
    }
   else
  {
    i++;j--;
   }

    }

if(f==1)
   printf("NOT PALINDROME\n");
else
   printf("PALINDROME\n");


}

void func(int sockfd)
{
    char buff[MAX];
    int n;

    for (;;) {
        bzero(buff, MAX);
        read(sockfd, buff, sizeof(buff));
        printf("From client: %s", buff);
        palindrome(buff);

}
}

// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
    printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));


    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);


    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");


    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);


    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");

    func(connfd);
    close(sockfd);
}
