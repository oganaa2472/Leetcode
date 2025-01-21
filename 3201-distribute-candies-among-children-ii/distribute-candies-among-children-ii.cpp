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
         long long totalWays = binomialCoefficient(n + 2, 2); // Total ways without limits

    // Subtract cases where one child exceeds the limit
    for (int i = 1; i <= 3; ++i) {
        totalWays -= binomialCoefficient(n - (limit + 1) + 2, 2);
    }

    // Add back overlaps for cases where two children exceed the limit
    for (int i = 1; i <= 3; ++i) {
        totalWays += binomialCoefficient(n - 2 * (limit + 1) + 2, 2);
    }

    // Subtract cases where all three children exceed the limit
    totalWays -= binomialCoefficient(n - 3 * (limit + 1) + 2, 2);

    return totalWays;
    }
};