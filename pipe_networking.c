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

//UPSTREAM = to the server / from the client
//DOWNSTREAM = to the client / from the server
/*=========================
  server_setup

  creates the WKP and opens it, waiting for a  connection.
  removes the WKP once a connection has been made

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_setup() {
  // Create WKP
  char * wkp = "./WKP";
  mkfifo(wkp, 0666);
  printf("WKP created\n");
  // Open WKP (Read)
  int syn = open(WKP, O_RDONLY);
  // Remove WKP
  remove(wkp);
  printf("WKP removed\n");
  return syn;
}

/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe (Client's private pipe).

  returns the file descriptor for the upstream pipe (see server setup).
  =========================*/
int server_handshake(int *to_client) {
  // Server Setup
  int syn = server_setup();
  // Read PP
  char pp[256];
  read(syn, pp, sizeof(pp));
  printf("Read pp named %s\n", pp);
  // Opening PP (Write)
  int syn_ack = open(pp, O_WRONLY);
  // Making random SYN_ACK
  int random = rand();
  char buffer[256];
  sprintf(buffer, "%d", random);
  // Sending SYN_ACK
  write(syn_ack, buffer, strlen(buffer)+1);
  
  // Reading ACK
  char recieved[256];
  read(syn, recieved, sizeof(received));
  printf("Read wkp for mesage %s\n", recieved);
  int from_client;
  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  // WKP Address
  char * wkp = "./WKP";
  // Create PP
  char * pp = "./PP";
  mkfifo(pp, 0666);
  // Open WKP (Write)
  int syn = open(wkp, O_WRONLY);
  // Sending PP
  write(syn, pp, strlen(pp)+1);
  // Open PP (Read)
  int syn_ack = open(pp, O_RDONLY);
  // Remove PP
  remove(pp);
  // Reading SYN_ACK
  char buffer[256];
  read(syn_ack, buffer, sizeof(buffer));
  // Creating ACK
  int received = atoi(buffer);
  recieved ++;
  char sending[256];
  sprintf(sending, "%d", buffer);
  // Sending ACK
  write(syn, sending, strlen(sending)+1);
  int from_server;
  return from_server;
}


/*=========================
  server_connect
  args: int from_client

  handles the subserver portion of the 3 way handshake

  returns the file descriptor for the downstream pipe.
  =========================*/
int server_connect(int from_client) {
  int to_client  = 0;
  return to_client;
}
