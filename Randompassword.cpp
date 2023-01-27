#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, length;
    char password[20];

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    srand(time(0));  // Seed the random number generator with the current time

    for (i = 0; i < length; i++) {
        // Generate a random number between 33 and 126 (printable ASCII characters)
        int r = rand() % (126 - 33 + 1) + 33;
        password[i] = (char)r;
    }

    password[i] = '\0';  // Null-terminate the string

    printf("Generated password: %s\n", password);

    return 0;
}

