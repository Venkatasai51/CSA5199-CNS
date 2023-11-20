#include <stdio.h>
#include <string.h>
void decrypt(char *ciphertext) {
    int length = strlen(ciphertext);
        float frequency[] = {8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15,
                         0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06,
                         2.76, 0.98, 2.36, 0.15, 1.97, 0.07};
    char most_common_letter = 'e';
    int shift = ciphertext[0] - most_common_letter;
    printf("Decrypted Text:\n");
    for (int i = 0; i < length; i++) {
        char current_char = ciphertext[i];
        if ((current_char >= 'A' && current_char <= 'Z') ||
            (current_char >= 'a' && current_char <= 'z')) {
            current_char -= shift;
            if ((current_char >= 'A' && current_char <= 'Z' && current_char < 'A') ||
                (current_char >= 'a' && current_char <= 'z' && current_char < 'a')) {
                current_char += 26;
            }
            printf("%c", current_char);
        } else {
            printf("%c", current_char);
        }
    }
}
int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    printf("Decrypted Text:\n");
    decrypt(ciphertext);

    return 0;
}

