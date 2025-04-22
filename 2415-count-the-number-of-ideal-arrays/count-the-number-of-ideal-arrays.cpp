#include <vector>
#include <numeric> // For std::iota
#include <map>

using namespace std;

class Solution {
private:
    // Constants for modulo arithmetic and array sizes
    static const int MOD = 1e9 + 7;
    // Maximum N needed for nCr calculation: C(e + n - 1, n - 1)
    // Max e ~ log2(10000) = 14. Max N ~ 14 + 10000 - 1 = 10013.
    // Use a slightly larger buffer.
    static const int MAX_COMB_N = 10000 + 14 + 1;
    // Max value for the 'maxValue' input + 1 for array indexing
    static const int MAX_VAL = 10001;

    // Static members for precomputed data to persist across test cases
    static vector<long long> fact;       // Factorials modulo MOD
    static vector<long long> invFact;    // Modular inverse of factorials
    static vector<int> spf;          // Smallest Prime Factor for sieve
    static bool precomputed; // Flag to ensure precomputation runs only once

    // Helper: Modular exponentiation (base^exp % MOD)
    static long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper: Modular inverse using Fermat's Little Theorem (for prime MOD)
    static long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    // Performs one-time precomputation of factorials, inverses, and SPF
    static void ensure_precomputation() {
        if (precomputed) return; // Exit if already done

        // Resize vectors to required sizes
        fact.resize(MAX_COMB_N);
        invFact.resize(MAX_COMB_N);
        spf.resize(MAX_VAL);

        // --- Precompute Factorials and their Modular Inverses ---
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i < MAX_COMB_N; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
            invFact[i] = modInverse(fact[i]); // Calculate inverse on the fly
        }

        // --- Precompute Smallest Prime Factor (SPF) using Sieve ---
        iota(spf.begin(), spf.end(), 0); // Fill spf[i] = i
        // Mark 0 and 1 as non-prime/invalid SPF
        if (spf.size() > 0) spf[0] = -1;
        if (spf.size() > 1) spf[1] = -1;

        for (int i = 2; (long long)i * i < MAX_VAL; ++i) {
             if (i >= spf.size()) break; // Safety bounds check
            // If i is prime (its smallest prime factor is itself)
            if (spf[i] == i) {
                // Mark multiples of i
                for (int j = i * i; j < MAX_VAL; j += i) {
                     if (j >= spf.size()) break; // Safety bounds check
                    // Update only if j hasn't been marked by a smaller prime factor yet
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        precomputed = true; // Mark precomputation as done
    }

    // Helper: Calculate nCr (Combinations) using precomputed values
    static long long nCr(int n_val, int r_val) {
        // Basic validation
        if (r_val < 0 || r_val > n_val) {
            return 0;
        }
        // Check if n_val is within the precomputed range
        if (n_val >= MAX_COMB_N) {
            // This indicates MAX_COMB_N might be too small or there's a logic error
            // Handle appropriately, returning 0 might hide issues.
             // cerr << "Error: nCr request out of bounds: N=" << n_val << endl;
             return 0;
        }
        // Calculate nCr = n! / (r! * (n-r)!) using modular inverses
        // n! * inv(r!) * inv((n-r)!) % MOD
        return (((fact[n_val] * invFact[r_val]) % MOD) * invFact[n_val - r_val]) % MOD;
    }

    // Instance variable to store maxValue for context in helper methods if needed
    // (Could also pass maxValue as parameter to getPrimeFactorization)
    int currentMaxValue = 0;

    // Helper: Get prime factorization of a number using the precomputed SPF array
    // Made it const as it doesn't modify the Solution object's logical state
    map<int, int> getPrimeFactorization(int num) const {
        map<int, int> factors;
        // Basic input validation against potential array bounds
        if (num >= MAX_VAL || num < 0) {
             return factors; // Return empty map for invalid input relative to SPF array
        }
        if (num <= 1) return factors; // Factorization of <= 1 is empty

        while (num > 1) {
            int prime_factor = spf[num];
            // Safety checks for invalid SPF values (e.g., for 0, 1 or if sieve failed)
             if (prime_factor <= 0 || prime_factor > currentMaxValue || prime_factor >= MAX_VAL) {
                 // This indicates an issue, break to avoid potential infinite loops/errors
                  // cerr << "Error: Invalid SPF encountered for num=" << num << ", spf=" << prime_factor << endl;
                 break;
             }
            factors[prime_factor]++; // Increment count for this prime factor
            num /= prime_factor;     // Divide num by its smallest prime factor
             // Check bounds again after division
             if (num >= MAX_VAL || num < 0) break;
        }
        return factors;
    }

public:
    // Main function to calculate the number of ideal arrays
    int idealArrays(int n, int maxValue) {

        ensure_precomputation(); // Ensure all static data is initialized
        currentMaxValue = maxValue; // Store maxValue for potential use in helpers

        long long total_ideal_arrays = 0;

        // Iterate through all possible values 'v' for the last element arr[n-1]
        for (int v = 1; v <= maxValue; ++v) {
            // 1. Get the prime factorization of the current ending value 'v'
            map<int, int> factors = getPrimeFactorization(v);

            // 2. Calculate the number of ways to form sequences ending in 'v'
            // This is the product of ways for each prime factor's exponent sequence
            long long ways_for_v = 1; // Initialize ways for this 'v'

            for (auto const& [prime, exponent] : factors) {
                // For a prime p with exponent e in v, we need the number of non-decreasing
                // sequences of length n: c_0 <= c_1 <= ... <= c_{n-1} = e.
                // This count is given by C(e + n - 1, n - 1) using stars and bars.
                int N = exponent + n - 1;
                int K = n - 1; // The second argument for nCr can also be 'exponent'

                // Calculate combinations C(N, K)
                long long combinations = nCr(N, K);

                // Multiply the result into ways_for_v (modulo MOD)
                ways_for_v = (ways_for_v * combinations) % MOD;

                // Optimization: if combinations is 0 at any point, the total ways for 'v' is 0
                if (ways_for_v == 0) {
                    break;
                }
            }

            // 3. Add the ways for this ending value 'v' to the total count
            total_ideal_arrays = (total_ideal_arrays + ways_for_v) % MOD;
        }

        // Return the final count cast to int
        return (int)total_ideal_arrays;
    }
};

// Initialize static members outside the class definition in the global scope
vector<long long> Solution::fact;
vector<long long> Solution::invFact;
vector<int> Solution::spf;
bool Solution::precomputed = false;