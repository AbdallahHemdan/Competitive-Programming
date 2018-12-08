// Generates all the prime numbers from 1 to the given number n
// using Sieve of Eratosthenes' algorithm.
// After calling this function, prime[i] will be equal 1 if i is prime, 0 otherwise.
// O(n.log(log(n)))
bool prime[N];
void generatePrimes(int n) {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (!prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
}
