class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        // 1. Массив дахь хамгийн их утгыг олж Sieve-ийн хэмжээг тодорхойлох
        int max_val = 1;
        for (int x : nums) {
            max_val = max(max_val, x);
        }

        // 2. Smallest Prime Factor (SPF) ашиглан Sieve байгуулах
        vector<int> spf(max_val + 1);
        for (int i = 1; i <= max_val; ++i) spf[i] = i;
        for (int i = 2; i * i <= max_val; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_val; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        // 3. Элемент бүрийн ялгаатай анхны хуваагчдыг олох туслах функц
        auto getPrimeFactors = [&](int val) {
            vector<int> factors;
            while (val > 1) {
                int p = spf[val];
                factors.push_back(p);
                while (val % p == 0) {
                    val /= p;
                }
            }
            return factors;
        };

        // 4. Массивын бүх тоонуудын хуваагчдыг урьдчилан бэлтгэх
        vector<vector<int>> factors(n);
        for (int i = 0; i < n; ++i) {
            factors[i] = getPrimeFactors(nums[i]);
        }

        // 5. Sliding Window (Two Pointers)
        vector<int> prime_freq(max_val + 1, 0);
        int distinct_primes = 0;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            // Баруун талын тооны хуваагчдыг цонхонд нэмэх
            for (int p : factors[right]) {
                if (prime_freq[p] == 0) {
                    distinct_primes++;
                }
                prime_freq[p]++;
            }

            // Хэрэв ялгаатай анхны хуваагчийн тоо k-аас хэтэрвэл зүүн заагчийг хумих
            while (distinct_primes > k) {
                for (int p : factors[left]) {
                    prime_freq[p]--;
                    if (prime_freq[p] == 0) {
                        distinct_primes--;
                    }
                }
                left++;
            }

            // Хамгийн их уртыг шинэчлэх
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};