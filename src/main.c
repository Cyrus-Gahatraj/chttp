#include "server.h"
#include "common.h"
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *handle_client(void* arg){
	int client_socket = *((int*)arg);
	free(arg);
	recv_request(client_socket);	// receive request from client
	send_response(client_socket);	// send response to client
	close(client_socket);

	return NULL;
}

int main(){
	Server* server = init_server();

	int binding = bind(server->socket, (void*) &server->addr, sizeof(server->addr));
	if (binding < 0){
		perror("Binding Failed");
		exit(1);
	}
	listen(server->socket, 10);

	int client_socket;
	while (1) {
		client_socket = accept(server->socket, NULL, NULL);

		// Reattempt if accept failed
		if (client_socket < 0) continue;

		int* pclient = malloc(sizeof(int));
		*pclient = client_socket;

		pthread_t thread;
		pthread_create(&thread, NULL, handle_client, pclient);

		pthread_detach(thread);
	}

	return 0;
}
