#include <stdio.h>
#include <math.h>

// Function to calculate (base^exponent) % modulus
int power(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    // Public numbers
    int q = 23; // Prime modulus
    int a = 5;  // Primitive root modulo q

    // Alice's secret number
    int xAlice = 6;
    // Calculate A = (a^xAlice) % q
    int A = power(a, xAlice, q);

    // Bob's secret number
    int xBob = 15;
    // Calculate B = (a^xBob) % q
    int B = power(a, xBob, q);

    // Exchange A and B
    // Alice computes shared secret: sAlice = (B^xAlice) % q
    int sAlice = power(B, xAlice, q);
    // Bob computes shared secret: sBob = (A^xBob) % q
    int sBob = power(A, xBob, q);

    // Print shared secrets
    printf("Shared secret for Alice: %d\n", sAlice);
    printf("Shared secret for Bob: %d\n", sBob);

    return 0;
}

