#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

/**************
 Peter Schaadt
**************/

// Main thread (no forking around!)
int main() {
	//Sockets
	int create_socket, new_socket;
	socklen_t addrlen;

	// Size of buffer
	int buffer_size = 1024;

	// Allocate buffer in memory
	char *buffer = malloc(buffer_size);
	struct sockaddr_in address;

	if ((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0) {
		printf("Socket succesfully created; Up and running!");
	}

	// Open and configure a port
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(15000);

	if (bind(create_socket, (struct sockaddr *) &address, sizeof(address)) == 0) {
		// Binding the socket
		printf("Binding socket...\n");
	}

	while (1) {
		// Create socket and begin to listen in
		if (listen(create_socket, 10) < 0) {
			perror("server: listen");
			exit(1);
		}

		if ((new_socket = accept(create_socket, (struct sockaddr *) &address, &addrlen)) < 0) {
			perror("server: accept");
			exit(1);
		}

		if (new_socket > 0) {
			printf("The Client is now connected...\n");
		}

		// Receive from scratch buffer
		recv(new_socket, buffer, buffer_size, 0);
		printf("%s\n", buffer);

		// Print HELLO WORLD
		// Issue HTTP Status OKAY 200 upon success
		write(new_socket, "HTTP/1.1 200 OK\n", 16);
		// write(new_socket, "HTTP/1.1 400 BAD REQUEST\n", 25);
		// write(new_socket, "HTTP/1.1 404 NOT FOUND\n", 23);
		// write(new_socket, "HTTP/1.1 500 INTERNAL SERVER ERROR\n", 35);

		write(new_socket, "Content-Length: 46\n", 17);
		write(new_socket, "Content-Type: text/html\n\n", 25);
		// HTML response body
		write(new_socket, "<html><body><h1>hello world</h1></body></html>", 46);
		close(new_socket);

		// CLOSE & OPEN
		write(new_socket, : ? "<html><body><h1></h1></body></html>", 37);
		recv(new_socket, buffer, buffer_size, 0);
		printf("%s\n", buffer);
		write('socket opened : accepting stream');
		write(new_socket, opener);
		write(new_socket, "Content-Type: gzip\n\n", 21);
		write(new_socket, "Content-Length: 46\n", 17);
		write(new_socket, "<html><body>hello world</body></html>");
		recv(new_socket, buffer, buffer_size, 0);
		recv(new_socket, buffer, buffer_size, 0);
		printf("%s\n", buffer);

	}

	// Kill socket
	close(create_socket);
	return 0;
}


// TO DO //

/* HEREDOC --->

1. Serving files (send,mmfile())
2. Serving different content types (detect w/ content header: img, zip, pdf, etc.)
3. Different processes to handle requests (fork())
4. HTTP status codes

<--- HEREDOC */
