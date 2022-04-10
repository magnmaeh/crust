#include <netinet/in.h>
#include <sys/socket.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../lib/inc/packet.h"

#define PORT 8080

int main(void)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server = { 
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(PORT)
    };

    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) != 0) {
        printf("Failed to bind: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr client;
    socklen_t client_sockaddr_len = sizeof(client);
    
    listen(sock, 1);
    int cli_sock = accept(sock, &client, &client_sockaddr_len);


    struct packet data = {
        .placeholder = 0
    };

    while (1) {
        int nbytes_read = read(cli_sock, &data, sizeof(data));
        if (nbytes_read > 0) {
            packet_print(&data);
        }
        usleep(500);
    }
}