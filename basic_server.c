#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;
  // Handshake
  from_client = server_handshake( &to_client );
  // Sending Number
  int designatedSend = rand()%101;
  printf("Number Designated: %d\n", designatedSend);
  while(write(to_client, &designatedSend, sizeof(int))){
    sleep(1);
  }
}
