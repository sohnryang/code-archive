/*
 * Prime table generator
 */

bool prime_table[1000001];

void sieve() {
    for (int i = 0; i < 1000001; ++i) prime_table[i] = true;
    prime_table[1] = false;
    for (int i = 1; i < 1000001; ++i) {
        if (!prime_table[i]) continue;
        for (int j = i * 2; j < 1000001; j += i)
            prime_table[j] = false;
    }
}
