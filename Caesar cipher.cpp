#include <stdio.h>
#include <string.h>
void caesarCipher(char message[], int shift) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
    }
    printf("Shift %d: %s\n", shift, message);
}
int main() {
    char message[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
    for (int shift = 1; shift <= 25; shift++) {
        char encryptedMessage[100];
        strcpy(encryptedMessage, message);

        caesarCipher(encryptedMessage, shift);
    }
    return 0;
}
