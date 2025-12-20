class Solution {
public:
    long long lastInteger(long long n) {
        if(n==1) return 1;
        long long k = (n+1)/2;
        long long half = lastInteger(k);

        return 2*(k+1-half)-1;
    }
};