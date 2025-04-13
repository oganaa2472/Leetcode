class Solution {
public:
    int n1=1e9+7;
    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a%n1;
            a = a * a%n1;
            b >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long a = n/2+n%2;
        long long b = n/2;
        long long sum = binpow(5,a);
        long long sum2 = binpow(4,b);
        int sum3= (sum2 * sum)%n1;
        return sum3;
    }
};