class Solution {
public:
    const long long MOD = 1e9 + 7;


    long long modPow(long long a, long long b) {
        long long res = 1;

        while(b) {
            if(b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }


    long long comb(long long n, long long r) {

        if(r < 0 || r > n)
            return 0;

        vector<long long> fact(n + 1);
        vector<long long> invFact(n + 1);

        fact[0] = 1;

        for(int i = 1; i <= n; i++)
            fact[i] = fact[i-1] * i % MOD;


        invFact[n] = modPow(fact[n], MOD-2);


        for(int i = n; i >= 1; i--)
            invFact[i-1] = invFact[i] * i % MOD;


        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }


    int countValidSequences(int n, int k) {

        // All positive sequences
        long long all = comb(n-1, k-1);


        // All odd sequences
        long long allOdd = 0;


        if(n >= k && (n-k)%2 == 0) {

            long long x = (n-k)/2;

            // C(x+k-1, k-1)
            allOdd = comb(x+k-1, k-1);
        }


        long long ans = (all - allOdd + MOD) % MOD;

        return ans;
    }
};