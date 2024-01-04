#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Ba�lant� yap�lacak sunucu bilgileri
    const char* server_ip = "127.0.0.1";
    const int server_port = 8080;

    // Soket olu�turma
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Soket olu�turma hatas�");
        exit(EXIT_FAILURE);
    }

    // Sunucu adres bilgilerini ayarlama
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &(server_address.sin_addr));

    // Sunucuya ba�lanma
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Ba�lant� hatas�");
        close(client_socket); // Hata durumunda soketi kapat
        exit(EXIT_FAILURE);
    }

    // Ba�lant� ba�ar�l�, �imdi soketi kapat
    close(client_socket);

    printf("Ba�lant� kesildi\n");

    return 0;
}

