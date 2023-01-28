#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        plaintext[i] = (plaintext[i] + key[j]) % 256;
    }
}

int main() {
    char plaintext[] = "HELLO WORLD";
    char key[] = "SECRET";
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}

