#include "pipe_networking.h"

static void sighandler(int signo){
  if (signo == SIGINT){
    remove("./WKP");
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGPIPE, sighandler);
  int to_client;
  int from_client;
  while(1){
    // printf("Attempting Hand Shake\n");
    from_client = server_handshake( &to_client );
    // printf("Hand Shake Success\n");

    int designatedSend = rand()%101;
    printf("Number Designated: %d\n", designatedSend);
    while(write(to_client, &designatedSend, sizeof(int)) != -1){
        sleep(1);
    }
    close(to_client);
    close(from_client);
    // sleep(10);
  }
}
