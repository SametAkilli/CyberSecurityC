#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int listen_fd_ipv4, listen_fd_ipv6, connection_fd;
    struct sockaddr_in server_addr_ipv4;
    struct sockaddr_in6 server_addr_ipv6;
    socklen_t client_len;
    
    
    listen_fd_ipv4 = socket(AF_INET, SOCK_STREAM, 0);
    listen_fd_ipv6 = socket(AF_INET6, SOCK_STREAM, 0);

    server_addr_ipv4.sin_family = AF_INET;
    server_addr_ipv4.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr_ipv4.sin_port = htons(80);

    server_addr_ipv6.sin6_family = AF_INET6;
    server_addr_ipv6.sin6_addr = in6addr_any; 
    server_addr_ipv6.sin6_port = htons(80);

    bind(listen_fd_ipv4, (struct sockaddr *) &server_addr_ipv4, sizeof(server_addr_ipv4));
    bind(listen_fd_ipv6, (struct sockaddr *) &server_addr_ipv6, sizeof(server_addr_ipv6));

    listen(listen_fd_ipv4, 5);
    listen(listen_fd_ipv6, 5);

    client_len = sizeof(server_addr_ipv4); 

    while (1) {
        
        connection_fd = accept(listen_fd_ipv4, (struct sockaddr *) &server_addr_ipv4, &client_len);
        if (connection_fd < 0) {
            perror("IPv4 accept");
        } else {
            
            close(connection_fd);
        }

        connection_fd = accept(listen_fd_ipv6, (struct sockaddr *) &server_addr_ipv6, &client_len);
        if (connection_fd < 0) {
            perror("IPv6 accept");
        } else {
            
            close(connection_fd);
        }
    }

   
    return 0;
}

