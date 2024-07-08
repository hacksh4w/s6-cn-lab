#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
  int clientfd;
  struct sockaddr_in serverAddr, clientAddr;
  char buff[1024];
  socklen_t serverAddrSize;

  // create client socket
  clientfd = socket(AF_INET, SOCK_DGRAM,0);
  
  if (clientfd == -1) {
     printf("Scoket creation failed \n");
     exit(0); // error status
  }
  else 
      printf("Socket successfully created \n");
  //assign IP and POrt
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(2002);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
  serverAddrSize = sizeof(serverAddr);

  //bind 
  bind(clientfd,(struct sockaddr*)&serverAddr,serverAddrSize);
  
  //send message to client
  printf("Sending message to sevrer");
  strcpy(buff, "Hi, server, this is clienttt");
  sendto(clientfd,buff,strlen(buff),0, (struct sockaddr *)&serverAddr,serverAddrSize);

  //recv msg from server
  recvfrom(clientfd,buff,sizeof(buff),0, (struct sockaddr *)&serverAddr, &serverAddrSize);
  printf("Received msg from server :%s",buff);

  close(clientfd);
  return 0;
}
