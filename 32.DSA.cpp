#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Modular exponentiation
unsigned long mod_exp(unsigned long base, unsigned long exponent, unsigned long modulus) {
    unsigned long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

// Modular inverse
unsigned long mod_inverse(unsigned long a, unsigned long modulus) {
    long m0, m1, m2, q, temp;
    m0 = modulus;
    m1 = a % modulus;

    for (int i = 2; i <= 10; i++) {
        m2 = m0 % m1;
        q = m0 / m1;
        temp = m1;
        m1 = m2;
        m0 = temp;
        if (m2 == 0) {
            return -1;
        }
    }

    m0 = modulus;
    m1 = a % modulus;
    m2 = 0; q = 0; temp = 0;

    while (m1 > 1) {
        temp = m0 - m0 % m1;
        q = temp / m1;
        m0 = m1;
        m1 = m0 % m1;
        m2 = temp;
    }

    if (m1 == 1) {
        return (m2 - modulus) % modulus;
    } else {
        return -1;
    }
}

// Generate a prime number
unsigned long generate_prime() {
    srand((unsigned int)time(NULL));

    unsigned long candidate = rand() % (1 << 20) + (1 << 19);

    while (1) {
        int is_prime = 1;
        for (unsigned long i = 2; i <= sqrt(candidate); i++) {
            if (candidate % i == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            return candidate;
        }

        candidate++;
    }
}

// Generate 'g' as a primitive root modulo 'p'
unsigned long generate_g(unsigned long p, unsigned long q) {
    srand((unsigned int)time(NULL));

    unsigned long h = rand() % (p - 2) + 2; // Random number in the range [2, p-1]

    return mod_exp(h, (p - 1) / q, p);
}

// Generate DSA parameters (p, q, g)
void generate_dsa_params(unsigned long *p, unsigned long *q, unsigned long *g) {
    *q = generate_prime();
    *p = *q * 2 + 1;

    while (1) {
        *p = generate_prime();
        *g = generate_g(*p, *q);

        unsigned long exp_result = mod_exp(*g, *q, *p);

        if (exp_result != 1) {
            break;
        }
    }
}

// Generate DSA keys (x, y)
void generate_dsa_keys(unsigned long p, unsigned long q, unsigned long g, unsigned long *x, unsigned long *y) {
    *x = rand() % (q - 1) + 1; // Random number in the range [1, q-1]
    *y = mod_exp(g, *x, p);
}

// Generate the DSA signature (r, s)
void sign_dsa(const char *message, unsigned long p, unsigned long q, unsigned long g, unsigned long x, unsigned long *r, unsigned long *s) {
    unsigned long k;
    unsigned long k_inv;
    unsigned long z;

    do {
        do {
            k = rand() % (q - 1) + 1; // Random number in the range [1, q-1]
            *r = mod_exp(g, k, p) % q;
        } while (*r == 0);

        k_inv = mod_inverse(k, q);
        z = *(unsigned long *)message;

        *s = (k_inv * (z + x * (*r))) % q;
    } while (*s == 0);
}

// Verify the DSA signature
int verify_dsa(const char *message, unsigned long p, unsigned long q, unsigned long g, unsigned long y, unsigned long r, unsigned long s) {
    unsigned long w, u1, u2, v;
    unsigned long z = *(unsigned long *)message;

    w = mod_inverse(s, q);
    u1 = (z * w) % q;
    u2 = (r * w) % q;

    v = ((mod_exp(g, u1, p) * mod_exp(y, u2, p)) % p) % q;

    return v == r;
}

int main() {
    unsigned long p, q, g, x, y;
    unsigned long r, s;
    const char *message = "Hello, DSA!";

    generate_dsa_params(&p, &q, &g);
    generate_dsa_keys(p, q, g, &x, &y);

    printf("DSA Parameters:\n");
    printf("p: %lu\n", p);
    printf("q: %lu\n", q);
    printf("g: %lu\n", g);

    printf("DSA Public Key (y): %lu\n", y);
    printf("DSA Private Key (x): %lu\n", x);

    sign_dsa(message, p, q, g, x, &r, &s);

    printf("DSA Signature (r, s): (%lu, %lu)\n", r, s);

    if (verify_dsa(message, p, q, g, y, r, s)) {
        printf("Signature is valid!\n");
    } else {
        printf("Signature is invalid!\n");
    }

    return 0;
}

