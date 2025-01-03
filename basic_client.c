#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  //
  // printf("Handshake achieved\n");
  // write(to_server, "a", 1);
  // char buffer[2];
  // read(from_server, buffer, sizeof(buffer));
  // printf("Send and then recieved %s\n", buffer);
}
