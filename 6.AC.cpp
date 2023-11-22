#include <stdio.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 0;
}

void encrypt(char text[], int keyA, int keyB) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            text[i] = (char)(((keyA * (text[i] - 'A') + keyB) % 26) + 'A');
        }
    }
}

void decrypt(char text[], int keyA, int keyB) {
    int i, a_inv = modInverse(keyA, 26);
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            text[i] = (char)(((a_inv * (text[i] - 'A' - keyB + 26)) % 26) + 'A');
        }
    }
}

int main() {
    char text[100];
    int keyA, keyB;

    printf("Enter text to encrypt: ");
    scanf("%[^\n]s", text);

    printf("Enter key A (must be coprime with 26): ");
    scanf("%d", &keyA);

    printf("Enter key B: ");
    scanf("%d", &keyB);

    encrypt(text, keyA, keyB);
    printf("Encrypted text: %s\n", text);

    decrypt(text, keyA, keyB);
    printf("Decrypted text: %s\n", text);

    return 0;
}

