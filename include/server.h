#pragma once
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

typedef struct Server {
	int socket;
	struct sockaddr_in addr;
} Server;

Server* init_server();
void send_response(int client_socket);
void recv_request(int client);

