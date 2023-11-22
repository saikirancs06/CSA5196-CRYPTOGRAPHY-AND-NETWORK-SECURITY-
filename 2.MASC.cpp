#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to perform monoalphabetic substitution encryption
void encrypt(char *plaintext, char *key) {
    int i;

    // Convert the key to uppercase
    for (i = 0; key[i] != '\0'; i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt the plaintext
    while (*plaintext) {
        char currentChar = toupper(*plaintext);

        if (isalpha(currentChar)) {
            // If the character is alphabetic, substitute it using the key
            printf("%c", key[currentChar - 'A']);
        } else {
            // If the character is not alphabetic, leave it unchanged
            printf("%c", *plaintext);
        }

        plaintext++;
    }

    printf("\n");
}

int main() {
    char plaintext[100];
    char key[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; // Example key (reverse alphabet)

    // Input the plaintext
    printf("Enter the plaintext to be encrypted (up to 100 characters): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove the newline character

    // Encrypt the plaintext using monoalphabetic substitution
    printf("Encrypted message: ");
    encrypt(plaintext, key);

    return 0;
}

