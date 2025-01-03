#include "pipe_networking.h"

int rand(){ // generates random int
  int buff[1];
  int random = open("/dev/urandom", O_RDONLY, 0);
  read(random,buff,4);
  close(random);
  if(buff[0] < 0){
    buff[0] *= -1;
  }
  return *buff;
}

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  // 
  // int designatedSend = rand()%101;
  // printf("Sending integer: %d\n", designatedSend);
  // char buffer[2];
  // read(from_client, buffer, sizeof(buffer));
  // printf("Recieved %s and sent a message\n", buffer);
  // write(to_client, "b", 1);
}
