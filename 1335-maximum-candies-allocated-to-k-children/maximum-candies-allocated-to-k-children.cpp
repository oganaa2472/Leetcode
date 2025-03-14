class Solution {
public:
    
    long long k ;
    bool check(long long mid,vector<int>& c){
        
        long long sum = 0;
        long long i = 0;
        for(int i = 0;i<c.size();i++){
            sum+=c[i]/mid;
        }
        // cout<<sum<<" "<<endl; 
        return sum>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long right = 1e7;
        
        this->k = k;
        long long left = 1;
        long long ans = 0;
        while(left<=right){
            long long mid = left+(right-left)/2;
            if(check(mid,candies)){
                ans = max(ans,mid);
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};