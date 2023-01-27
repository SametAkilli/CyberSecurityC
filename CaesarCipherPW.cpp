#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int i;
    int message_len = strlen(message);

    for (i = 0; i < message_len; i++) {
        // Only encrypt letters, not spaces or punctuation
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
    }
}

void decrypt(char *message, int key) {
    int i;
    int message_len = strlen(message);

    for (i = 0; i < message_len; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[1000];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}

