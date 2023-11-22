#include <stdio.h>
#include <string.h>

// Function to perform CFB encryption
void encrypt_cfb(const char *plaintext, const char *key, const char *iv, char *ciphertext) {
    int len = strlen(plaintext);
    int key_len = strlen(key);

    // Use the key and IV directly for simplicity. In real-world scenarios, use a proper key derivation function.
    for (int i = 0; i < len; ++i) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
        ciphertext[i] = ciphertext[i] ^ (i == 0 ? iv[i % key_len] : ciphertext[i - 1]);
    }

    ciphertext[len] = '\0';  // Null-terminate the string
}

// Function to perform CFB decryption
void decrypt_cfb(const char *ciphertext, const char *key, const char *iv, char *decrypted_text) {
    int len = strlen(ciphertext);
    int key_len = strlen(key);

    for (int i = 0; i < len; ++i) {
        decrypted_text[i] = ciphertext[i] ^ key[i % key_len];
        decrypted_text[i] = decrypted_text[i] ^ (i == 0 ? iv[i % key_len] : ciphertext[i - 1]);
    }

    decrypted_text[len] = '\0';  // Null-terminate the string
}

int main() {
    const char *plaintext = "Hello, CFB Mode!";
    const char *key = "encryptionkey";
    const char *iv = "initialvector";

    char ciphertext[256];
    char decrypted_text[256];

    // Encrypt
    encrypt_cfb(plaintext, key, iv, ciphertext);

    // Print encrypted text
    printf("Original Text: %s\n", plaintext);
    printf("Encrypted Text: %s\n", ciphertext);

    // Decrypt
    decrypt_cfb(ciphertext, key, iv, decrypted_text);

    // Print decrypted text
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}

