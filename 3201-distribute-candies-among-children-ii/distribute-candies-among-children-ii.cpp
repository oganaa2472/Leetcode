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
         long long total = binomialCoefficient(n + 2, 2);

    // Subtract cases where one child gets more than 'limit' candies
    long long invalid1 = 3 * binomialCoefficient((n - (limit + 1)) + 2, 2);

    // Add cases where two children get more than 'limit' candies (inclusion-exclusion)
    long long invalid2 = 3 * binomialCoefficient((n - 2 * (limit + 1)) + 2, 2);

    // Subtract cases where all three children get more than 'limit' candies
    long long invalid3 = binomialCoefficient((n - 3 * (limit + 1)) + 2, 2);

    // Apply inclusion-exclusion principle
    long long validWays = total - invalid1 + invalid2 - invalid3;

    return validWays;
    }
};