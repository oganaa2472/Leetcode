class Solution {
public:
    
    // Биномиал коэффициент C(n, r) тооцоолох функц
    long long binomialCoefficient(int n, int r) {
        if (r > n || r < 0) return 0;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }
        long long distributeCandies(int n, int limit) {
            long long answer = 0;

            long long fmax = min(limit,n);
            long long fmin = max(0,n-(2*limit));

            for(int i = fmin; i<=fmax;i++){
                long long left = min(limit,n-i);
                long long right = max(0,n-i-limit);
                answer += left - right + 1;
            }
            return answer;
    }
};