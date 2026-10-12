class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n % 2 != 0) return false;
        if (n < 2) return false;

        long long a = 0;
        long long b = 1;
        long long target = n / 2;

        while (b <= target) {
            if (b == target) return true;

            int temp = b;
            b = a + b;
            a = temp;
        }

        return false;
    }
};