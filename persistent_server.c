#include "pipe_networking.h"

static void sighandler(int signo){
  if (signo == SIGINT){
    remove("./WKP");
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGPIPE, SIG_IGN);
  int to_client;
  int from_client;
  while(1){
    // Handshake
    printf("Attempting handshake\n");
    from_client = server_handshake( &to_client );
    printf("Handshake accomplished\n");
    // Sending Number
    int designatedSend = rand()%101;
    printf("Number Designated: %d\n", designatedSend);
    while(write(to_client, &designatedSend, sizeof(int)) != -1){
        sleep(1);
    }
    printf("Client Exited\n");
    // Delete on Dis
    close(to_client);
    close(from_client);
  }
}
