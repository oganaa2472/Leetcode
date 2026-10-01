class Solution {
public:
    int check(vector<int>&nums,int k,int mid){
        int cnt = 0;
        int n = nums.size();
        int chooseIndex = -1;
        for(int i = 0;i<n;i++){
            if(nums[i]<=mid){
                if(chooseIndex == -1){
                    chooseIndex = i;
                    cnt++;
                }else if(i-chooseIndex>1){
                    cnt++;
                    chooseIndex = i;
                }
                
            }
        
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};