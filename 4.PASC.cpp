#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Vigenere encryption
void vigenereEncrypt(char plaintext[], char key[]) {
    int i, j;
    int plainLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < plainLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        // Encrypt uppercase letters
        if (isupper(plaintext[i]))
            plaintext[i] = (char)(((plaintext[i] - 'A' + key[j] - 'A') % 26) + 'A');
        // Encrypt lowercase letters
        else if (islower(plaintext[i]))
            plaintext[i] = (char)(((plaintext[i] - 'a' + key[j] - 'A') % 26) + 'a');
    }
}

int main() {
    char plaintext[1000], key[100];
    
    // Input plaintext and key
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    strtok(plaintext, "\n");
    strtok(key, "\n");

    // Encrypt the plaintext
    vigenereEncrypt(plaintext, key);

    // Display the encrypted text
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}

