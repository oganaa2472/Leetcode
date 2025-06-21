class Solution {
    vector<bool> isPrime;
    const int MAXN = 100000;
public:
    Solution() : isPrime(100000, true) {
        sieve();
    }
    void sieve() {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= MAXN; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAXN; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, res = 0, prev = -1, curr = -1;

    
        multiset<int> ms;

        while(r < n){
            
            if(isPrime[nums[r]]){
                prev = curr;
                curr = r;
                ms.insert(nums[r]);
            }

        
            while(ms.size() && *ms.rbegin() - *ms.begin() > k){
                if(isPrime[nums[l]]){
                    ms.erase(ms.find(nums[l]));
                }
                l++;
            }
            if(ms.size() >= 2){
                
                res += (prev - l + 1);
            }
            r++;
        }

        
        return res;
    }
};