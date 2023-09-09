#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int listen_fd, connection_fd;
    struct sockaddr_in6 server_addr, client_addr;
    socklen_t client_len;

    listen_fd = socket(AF_INET6, SOCK_STREAM, 0);

    server_addr.sin6_family = AF_INET6;
    server_addr.sin6_addr = in6addr_any; 
    server_addr.sin6_port = htons(80);

    bind(listen_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(listen_fd, 5);

    client_len = sizeof(client_addr);

    while (1) {
        connection_fd = accept(listen_fd, (struct sockaddr *) &client_addr, &client_len);

        if (connection_fd < 0) {
            perror("accept");
            continue;
        }

       
        close(connection_fd);
    }

    return 0;
}

