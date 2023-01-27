#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int listen_fd, connection_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

   
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(80);

   
    bind(listen_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    
    listen(listen_fd, 5);

    client_len = sizeof(client_addr);
    connection_fd = accept(listen_fd, (struct sockaddr *) &client_addr, &client_len);

   
    if (!check_ip_address(client_addr.sin_addr.s_addr)) {
        
        close(connection_fd);
        return 0;
    }

   
    process_request(connection_fd);

    
    close(connection_fd);

    return 0;
}

