#include <stdio.h>

// Constants for XOR based on block size
#define XOR_CONSTANT_64 0x1B
#define XOR_CONSTANT_128 0x87

// Left shift by one position
unsigned char leftShiftOneBit(unsigned char value) {
    // Check if the leftmost bit is 1
    int carry = (value & 0x80) ? 1 : 0;
    // Left shift by one position
    value <<= 1;
    // If there was a carry, XOR with the constant
    if (carry) {
        value ^= XOR_CONSTANT_64; // For 64-bit block size
        // value ^= XOR_CONSTANT_128; // For 128-bit block size
    }
    return value;
}

// Generate subkeys for CMAC
void generateCMACSubkeys() {
    unsigned char subkey1 = 0;
    unsigned char subkey2;

    // Derive subkey 1
    subkey1 = leftShiftOneBit(subkey1);

    // Print the derived subkey 1
    printf("Subkey 1: 0x%02X\n", subkey1);

    // Derive subkey 2
    subkey2 = leftShiftOneBit(subkey1);

    // Print the derived subkey 2
    printf("Subkey 2: 0x%02X\n", subkey2);
}

int main() {
    printf("Subkey Generation for CMAC:\n");
    generateCMACSubkeys();

    return 0;
}

