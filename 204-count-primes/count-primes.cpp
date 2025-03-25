class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1,true);
        primes[0] = primes[1] = false;
        int cnt =0;
        for(int i = 2;i<n;i++){
            if(primes[i]){
                 cnt++;
                for(int j = i*2;j<n;j+=i){
                    
                    primes[j] = false;
                }
            }
        }
       
        return cnt;
    }
};