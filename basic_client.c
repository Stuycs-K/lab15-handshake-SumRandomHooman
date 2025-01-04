#include "pipe_networking.h"

int main() {
  signal(SIGPIPE, SIG_IGN);
  int to_server;
  int from_server;

  // Handshake
  from_server = client_handshake( &to_server );
  // Continually recieve number
  int recievedvalue;
  int error;
  while(read(from_server, &recievedvalue, sizeof(int))){
    printf("Recieved %d\n", recievedvalue);
  }
}
