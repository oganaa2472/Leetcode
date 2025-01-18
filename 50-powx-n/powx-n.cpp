class Solution {
public:
    double binPow(double x,long long n){
       if(n==0) return 1.00000;
       if(n<0){
        x = 1.0/x;
        n = -1*n;
       }
        double res = 1;
        while (n > 0) {
            if (n & 1)
                res = res * x;
            x = x * x;
            n >>= 1;
        }
        return res;
        }
    double myPow(double x, int n) {
        return binPow(x, (long long) n);
    }
};