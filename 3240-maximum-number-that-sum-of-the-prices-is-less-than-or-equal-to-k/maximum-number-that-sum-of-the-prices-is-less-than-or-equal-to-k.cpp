class Solution {
public:
    long long powerOf2(long long i){
        return 1LL<<i;
    }
     int countBits(long long n) {
        int count = 0;
        while(n) {
            count++;
            n = n >> 1;
        }        
        return count;
    } 
    bool check(long long k, int x, long long mid) {
    
        
    
        long long cnt = 0;
        for(int n = 52;n>=1;n--){

        
            if(n%x==0)// current x position
                cnt += (mid / powerOf2(n)) * (powerOf2(n - 1)) + max(0LL, (mid % powerOf2(n)) - powerOf2(n - 1));
       
        }
  

       
        return cnt <= k;
    }

    long long findMaximumNumber(long long k, int x) {
        long long left = 1, right = 1e15, ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(k, x, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans-1;
    }
};
