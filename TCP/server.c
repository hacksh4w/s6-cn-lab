#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main () {
    
    int serverfd, clientfd;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr; 
    socklen_t clientAddrSize;
    
    //create server socket + address
    serverfd = socket(AF_INET,SOCK_STREAM,0);
    if (serverfd == -1){
        printf("Server socket creation failed ...");
        exit(0);
    } else 
        printf("server socket creation is successful");
        
    
    // assigning ip and port address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5600);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    //binding newly created socket to given IP addr
    if(bind(serverfd, (struct sockaddr *)&serverAddr,sizeof(serverAddr)!=0){
        printf("SOcket binding failed \n");
        exit(0);
    } else 
        print("Socket successfully binded... \n");
    
    //listen for incoming client socket connections
    if(listen(serverfd,5) ==0){
        printf("Lisyening at port : 5600 \n");
    } else 
        printf("unable to listen, try again");
        
    // acceptin incoming connections
    clientfd = accept(serverfd,(struct sockAddr *)&clientAddr, &clientAddrSize);
     if (clientfd < 0 ) {
         printf("Server accept failed \n");
         exit(0);
     } else 
        printf("Server accept from client ...");
    
    // now to chat 
    recv(clientfd, buffer, sizeof(buffer));
    printf("Data received from client : %s", buffer);
    
    //send Data
    strcpy(buffer, "Hi, i am server\n");
    printf("sending data to client");
    send(clientfd, buffer, sizeof(buffer),0);
    
    
    
    //close socket connection 
    close(clientfd);
    close(serverfd);
    
    return 0;
}
