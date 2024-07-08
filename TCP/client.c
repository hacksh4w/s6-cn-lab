
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
   int clientfd;
   char buffer[1024];
   struct sockaddr_in serverAddr;
   socklen_t clientAddrSize;
   
   //create client & server clientAddrSize
   clientfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (clientfd == -1) {
       printf("Scoket creation failed \n");
       exit(0); // error status
   }
   else 
        printf("Socket successfully created \n");
    // Assigned IP, Port since sockaddr is made of both
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(5600);
   serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   
   //connecting client socket to server server
   if (connect(clientfd,(struct sockaddr *)&serverAddr, sizeof(serverAddr)) !=0) {
       printf("Connection to socket failed");
       exit(0);
   } else 
        printf("Sending data to server at port : 6265 \n");
   
   //to chat // accept buffer and string
    strcpy(buffer, "Hello there, i am client, how are u doing?");
    send(clientfd, buffer, sizeof(buffer),0);
    
   
   //close socket
   close(clientfd);
   return 0;
   
}
