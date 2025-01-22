class Solution {
public:
    const int MOD = 1000000007;

    long long pow_mod(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    long long compute_comb(long long a, long long b, long long mod) {
        if (b < 0 || b > a) return 0;
        long long res = 1;
        for (int i = 1; i <= b; ++i) {
            long long term = (a - b + i) % mod;
            term = term * pow_mod(i, mod - 2, mod) % mod;
            res = res * term % mod;
        }
        return res;
    }

    long long lucas(long long a, long long b, long long mod) {
        if (b == 0) return 1;
        long long a_mod = a % mod;
        long long b_mod = b % mod;
        if (b_mod > a_mod) return 0;
        return (lucas(a / mod, b / mod, mod) * compute_comb(a_mod, b_mod, mod)) % mod;
    }
    int minCost(int m, int n, int k) {
        long long T = (long long)m * n;
        if (k < 2 || k > T) return 0;

        long long inv6 = pow_mod(6, MOD - 2, MOD);

        long long m_mod = m % MOD;
        long long n_mod = n % MOD;

        long long term_x = (n_mod * n_mod) % MOD;
        term_x = term_x * m_mod % MOD;
        long long m_sq = (m_mod * m_mod) % MOD;
        long long m_sq_minus_1 = (m_sq - 1 + MOD) % MOD;
        term_x = term_x * m_sq_minus_1 % MOD;
        term_x = term_x * inv6 % MOD;

        long long term_y = (m_mod * m_mod) % MOD;
        term_y = term_y * n_mod % MOD;
        long long n_sq = (n_mod * n_mod) % MOD;
        long long n_sq_minus_1 = (n_sq - 1 + MOD) % MOD;
        term_y = term_y * n_sq_minus_1 % MOD;
        term_y = term_y * inv6 % MOD;

        long long sum_manhattan = (term_x + term_y) % MOD;

        long long a = T - 2;
        long long b = k - 2;
        long long comb_val = lucas(a, b, MOD);

        long long ans = (sum_manhattan * comb_val) % MOD;
        return (int)ans;
}
    int distanceSum(int m, int n, int k) {
       return minCost(m,n,k);
    }
    
};