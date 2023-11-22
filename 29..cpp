#include <stdio.h>
#include <stdint.h>

#define STATE_SIZE 25
#define CAPACITY_SIZE 576 // 1024 - 448
#define CAPACITY_WORDS (CAPACITY_SIZE / 64)

typedef uint64_t state[STATE_SIZE];

void printState(const state s) {
    for (int i = 0; i < STATE_SIZE; i++) {
        printf("%016lx ", s[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to check if all lanes in the capacity portion have at least one nonzero bit
int allNonzeroBits(const state s) {
    for (int i = CAPACITY_WORDS; i < STATE_SIZE; i++) {
        if (s[i] != 0) {
            return 1; // At least one nonzero bit found
        }
    }
    return 0; // All lanes are zero
}

// SHA-3 initialization function
void sha3Initialize(state s) {
    for (int i = 0; i < STATE_SIZE; i++) {
        s[i] = 0;
    }
}

// Simulate SHA-3 state update until all lanes in the capacity portion have at least one nonzero bit
void simulateSHA3(state s) {
    int rounds = 0;
    while (!allNonzeroBits(s)) {
        // Simulate SHA-3 state update (ignoring permutation)
        // In a real SHA-3 implementation, this would involve the Keccak-f permutation
        // For simplicity, just set some nonzero values in the capacity portion
        for (int i = CAPACITY_WORDS; i < STATE_SIZE; i++) {
            s[i] = 0x1; // Set a nonzero value
        }

        rounds++;
    }

    printf("Number of rounds: %d\n", rounds);
}

int main() {
    state sha3State;

    // Initialize SHA-3 state
    sha3Initialize(sha3State);

    printf("Initial SHA-3 State:\n");
    printState(sha3State);

    // Simulate SHA-3 state update until all lanes in the capacity portion have at least one nonzero bit
    simulateSHA3(sha3State);

    printf("Final SHA-3 State:\n");
    printState(sha3State);

    return 0;
}

