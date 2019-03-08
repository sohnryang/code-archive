/*
 * Binomial coefficient
 */

int bino(int n, int k) {
    if (n == k || k == 0) return 1;
    else return bino(n - 1, k - 1) + bino(n - 1, k);
}
