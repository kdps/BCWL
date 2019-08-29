#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>

#define SERVER_ADDR     "127.0.0.1"
#define MAXBUF          1024
#define PORT_FTP        21

int main(int argc, char *argv[]) {
  int socketFileDescriptor;
  
  struct sockaddr_in destination;
  
  socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0); // Descriptor referencing the socket
  
  //Internet Protocol => AF_INET : Address, PF_INET : Protocol
  if ( socketFileDescriptor == -1 ) { // It just return -1 If fail to connect
        perror("Socket"); // Print an error as a human-readable string
        exit(errno);      // 1
  }
  
  //if ( socketFileDescriptor == 0 ) { It return 0 If success to connect 
  
  /*
    struct sockaddr_in { 
      short sin_family;
      u_short sin_port;
      struct in_addr sin_addr; 
      char sin_zero[8];
    };

  */
  
  bzero(&destination, sizeof(destination)); // Refill to sockaddr_in(AF_INET) structor
  destination.sin_family = AF_INET;         // Address system (short)
  destination.sin_port = htons(PORT_FTP);   // <- convert to network bytes order / 16 bit port number
  
}
