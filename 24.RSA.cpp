#include <stdio.h>

// Function to calculate the greatest common divisor using Euclidean algorithm
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the modular multiplicative inverse using extended Euclidean algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    // Given public key values
    int e = 31;
    int n = 3599;

    // Find p and q using trial-and-error
    int p, q;
    for (p = 2; p < n; p++) {
        if (n % p == 0) {
            q = n / p;
            break;
        }
    }

    // Calculate Euler's totient function (f(n))
    int phi = (p - 1) * (q - 1);

    // Calculate the private key using the extended Euclidean algorithm
    int d = modInverse(e, phi);

    // Print the private key
    printf("Private key (d): %d\n", d);

    return 0;
}

