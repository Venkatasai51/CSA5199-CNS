#include <stdio.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
void decryptAffineCipher(char ciphertext[], int a, int b) {
    int m = 26; 
    int aInverse = modInverse(a, m);
    if (aInverse == -1) {
        printf("Invalid key 'a'. No modular inverse exists.\n");
        return;
    }
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int x = ciphertext[i] - 'A';
            int decryptedChar = (aInverse * (x - b + m)) % m;
            if (decryptedChar < 0)
                decryptedChar += m;
            printf("%c", 'A' + decryptedChar);
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            int x = ciphertext[i] - 'a';
            int decryptedChar = (aInverse * (x - b + m)) % m;
            if (decryptedChar < 0)
                decryptedChar += m;
            printf("%c", 'a' + decryptedChar);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}
int main() {
    char ciphertext[] = "YourCiphertextHere"; 
    int bIndex = 'B' - 'A';
    int uIndex = 'U' - 'A';
    int aGuess = (uIndex - bIndex + 26) % 26;
    for (int bGuess = 0; bGuess < 26; bGuess++) {
        printf("Key (a, b): (%d, %d)\nDecrypted Text: ", aGuess, bGuess);
        decryptAffineCipher(ciphertext, aGuess, bGuess);
    }
    return 0;
}

