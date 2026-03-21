#include "server.h"
#include "config.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_server_addr(struct sockaddr_in* addr){
	addr->sin_family = AF_INET;
	addr->sin_port = htons(PORT);
	inet_pton(AF_INET, IP, &addr->sin_addr);
}

Server* init_server(){
	Server* server = malloc(sizeof(Server));

	// AF_INET is IP version 4 addressing
	// SOCK_STREAM is use for TCP
	server->socket = socket(AF_INET, SOCK_STREAM, 0);
	fill_server_addr(&server->addr);

	return server; 
}

void recv_request(int client){
	char request_buffer[2048];
	recv(client, request_buffer, sizeof(request_buffer), 0);
	printf("%s\n", request_buffer);
}

void send_response(int client_socket){
	char content[1024];
	read_file(HTML_FILE, content, sizeof(content));

	char response_buffer[sizeof(content) + 128];
	snprintf(response_buffer, sizeof(response_buffer), 
			"HTTP/1.1 200 OK\n\n%s",
			content);

	send(client_socket, response_buffer, strlen(response_buffer), 0);
}
