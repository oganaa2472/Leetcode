class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1,true);

        for(int i = 2;i*i<=n;i++){
            if(primes[i]){
                for(int j = i*i;j<=n;j+=i){
                    primes[j] = false;
                }
            }
        }
        int c=0;
        for (int p = 2; p <n; p++) if (primes[p]) c++;
        return c;
    }
};