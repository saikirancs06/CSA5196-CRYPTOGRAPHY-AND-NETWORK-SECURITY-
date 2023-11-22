#include <stdio.h>
#include <string.h>

// Function to perform encryption using ECB mode
void encryptECB(char *plaintext, char *key, int block_size) {
    int i, j;

    // Assume plaintext and ciphertext have the same size
    int num_blocks = strlen(plaintext) / block_size;

    for (i = 0; i < num_blocks; i++) {
        // XOR each byte of the block with the corresponding byte of the key
        for (j = 0; j < block_size; j++) {
            plaintext[i * block_size + j] ^= key[j];
        }
        // In a real-world scenario, you would perform encryption using a block cipher here
        // For simplicity, we're simulating the operation by XORing with the key
    }
}

// Function to perform decryption using ECB mode
void decryptECB(char *ciphertext, char *key, int block_size) {
    // Decryption in ECB mode is the same as encryption
    encryptECB(ciphertext, key, block_size);
}

int main() {
    char plaintext[] = "This is a simple ECB mode example";
    char key[] = "secretKey";
    int block_size = 8; // Assume a block size of 8 for simplicity

    // Print original plaintext
    printf("Original plaintext: %s\n", plaintext);

    // Encrypt the plaintext
    encryptECB(plaintext, key, block_size);

    // Print the ciphertext
    printf("Encrypted ciphertext: %s\n", plaintext);

    // Decrypt the ciphertext
    decryptECB(plaintext, key, block_size);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

