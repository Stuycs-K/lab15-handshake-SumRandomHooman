#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  // printf("Attempting Hand Shake\n");
  from_server = client_handshake( &to_server );
  // printf("Hand Shake Success\n");
  
  int recievedvalue;
  while(read(from_server, &recievedvalue, sizeof(int))){
    printf("Recieved %d\n", recievedvalue);
  }
  
}
