#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
  int serverfd;
  struct sockaddr_in serverAddr, clientAddr;
  char buff[1024];
  socklen_t clientAddrSize;

  // create server socket
  serverfd = socket(AF_INET, SOCK_DGRAM,0);

  if (serverfd == -1) {
     printf("Scoket creation failed \n");
     exit(0); // error status
  }
  else 
      printf("Socket successfully created \n");
  //assign IP and POrt
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(2002);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
  clientAddrSize = sizeof(serverAddr);

  //bind
  bind(serverfd,(struct sockaddr*)&serverAddr,clientAddrSize);
  //listen to recv msg from server
  recvfrom(serverfd,buff,sizeof(buff),0, (struct sockaddr *)&serverAddr, &clientAddrSize);
  printf("Listening at port 2002\n");
  printf("Received msg from server : %s \n", buff);
  
  //send message to client
  strcpy(buff, "Hi, client, this is server");
  printf("Sending message to sevrer");
  sendto(serverfd,buff,strlen(buff),0, (struct sockaddr *)&serverAddr,clientAddrSize);


  close(serverfd);
  return 0;
}
