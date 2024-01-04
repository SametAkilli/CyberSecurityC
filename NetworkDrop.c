#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Baðlantý yapýlacak sunucu bilgileri
    const char* server_ip = "127.0.0.1";
    const int server_port = 8080;

    // Soket oluþturma
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Soket oluþturma hatasý");
        exit(EXIT_FAILURE);
    }

    // Sunucu adres bilgilerini ayarlama
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &(server_address.sin_addr));

    // Sunucuya baðlanma
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Baðlantý hatasý");
        close(client_socket); // Hata durumunda soketi kapat
        exit(EXIT_FAILURE);
    }

    // Baðlantý baþarýlý, þimdi soketi kapat
    close(client_socket);

    printf("Baðlantý kesildi\n");

    return 0;
}

