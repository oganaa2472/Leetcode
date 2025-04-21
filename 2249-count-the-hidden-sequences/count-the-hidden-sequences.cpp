class Solution {
public:
    long long bs(long long mid,long long lower,long long upper,vector<int>&nums){
        int n = nums.size();
        for(int i =0;i<n;i++){
            mid -= nums[n-i-1] ;
            if(mid>upper){
                return false;
            }
        }
        return true;
    }
     int bs2(int mid,int lower,int upper,vector<int>&nums){
        int n = nums.size();
        for(int i =0;i<n;i++){
            mid -= nums[n-i-1] ;
            if(mid<lower){
                return false;
            }
        }
        return true;
    }
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int count = 0;
        
        int n = differences.size();
        
        int left = lower;
        int right = upper;
        int ans = -1e5;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(bs(mid,lower,upper,differences)){
                left = mid+1;
                ans = mid;
            }else{
                right = mid-1;
            }
        }
        // cout<<ans<<" ";
        if(ans==-1e5) return 0;
        left = lower;
        right = ans;
        // cout<<"ans="<<ans<<endl;
        int ans2 = ans;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(bs2(mid,lower,upper,differences)){
                right=mid-1;
                ans2=right;
            }else{
                left=mid+1;
            }
        }
        
        // cout<<right<<" ";
        return ans-ans2;
    }
};