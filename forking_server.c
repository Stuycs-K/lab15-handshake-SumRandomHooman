#include "pipe_networking.h"

static void sighandler(int signo){
  if (signo == SIGINT){
    remove("./WKP");
    exit(0);
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGPIPE, SIG_IGN);
  int to_client;
  int from_client;
  int childnum = 1;
  while(1){
    // Handshake
    from_client = server_setup( &to_client );
    // Making a child
    pid_t subserver;
    subserver = fork();
    if(subserver<0){
      perror("fork fail");//output to stderr instead of stdout
      exit(1);
    }
    if(subserver == 0){
      server_handshake_half(&to_client, from_client);
      printf("Handshake achieved\n");
      // Sending Number
      int designatedSend = rand()%101;
      printf("Number Designated sending to client %d: %d\n",childnum ,designatedSend);
      while(write(to_client, &designatedSend, sizeof(int))){
          sleep(1);
      }
      printf("Loop terminates\n");
      // Closing Files
      close(to_client);
      close(from_client);
      // Telling child to kill self
      printf("Child told to kill self??\n");
      exit(0);
    }
    else{
      childnum ++;
    }
  }
}
