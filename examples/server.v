//import <sys/socket.h>
//import <arpa/inet.h>
//import <unistd.h>

int read_size;
struct sockaddr_in server, client;
char client_message[2000];

int socket_desc = socket(AF_INET, SOCK_STREAM, 0)

server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons( 9090 );

bind(socket_desc, (struct sockaddr*)&server, sizeof(server))

listen(socket_desc, 3)

int c = sizeof(struct sockaddr_in)
while (1) {
	int client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c)
	send(client_sock, client_message, recv(client_sock, client_message, 2000, 0), 0);
	close(client_sock)
}

close(socket_desc)
