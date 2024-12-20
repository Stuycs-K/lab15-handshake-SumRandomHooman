#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  // 
  // printf("Handshake achieved\n");
  // char buffer[2];
  // read(from_client, buffer, sizeof(buffer));
  // printf("Recieved %s and sent a message\n", buffer);
  // write(to_client, "b", 1);
}
