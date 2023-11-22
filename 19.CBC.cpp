#include <stdio.h>
#include <string.h>

// Function to perform CBC encryption
void encrypt_cbc(const char *plaintext, const char *key, const char *iv, char *ciphertext) {
    int len = strlen(plaintext);
    int key_len = strlen(key);

    // Use the key and IV directly for simplicity. In real-world scenarios, use a proper key derivation function.
    for (int i = 0; i < len; ++i) {
        ciphertext[i] = plaintext[i] ^ (i == 0 ? iv[i % key_len] : ciphertext[i - 1]);
        ciphertext[i] = ciphertext[i] ^ key[i % key_len];
    }

    ciphertext[len] = '\0';  // Null-terminate the string
}

// Function to perform CBC decryption
void decrypt_cbc(const char *ciphertext, const char *key, const char *iv, char *decrypted_text) {
    int len = strlen(ciphertext);
    int key_len = strlen(key);

    for (int i = 0; i < len; ++i) {
        decrypted_text[i] = ciphertext[i] ^ key[i % key_len];
        decrypted_text[i] = decrypted_text[i] ^ (i == 0 ? iv[i % key_len] : ciphertext[i - 1]);
    }

    decrypted_text[len] = '\0';  // Null-terminate the string
}

int main() {
    const char *plaintext = "Hello, CBC Mode!";
    const char *key = "encryptionkey";
    const char *iv = "initialvector";

    char ciphertext[256];
    char decrypted_text[256];

    // Encrypt
    encrypt_cbc(plaintext, key, iv, ciphertext);

    // Print encrypted text
    printf("Original Text: %s\n", plaintext);
    printf("Encrypted Text: %s\n", ciphertext);

    // Decrypt
    decrypt_cbc(ciphertext, key, iv, decrypted_text);

    // Print decrypted text
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}

