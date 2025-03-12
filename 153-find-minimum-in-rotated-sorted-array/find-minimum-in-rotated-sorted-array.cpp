class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(nums.size()==1) return nums[0];
        int ans = INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
          
          
           if(nums[left]<=nums[mid]){
                ans=min(nums[left],ans);
                left = mid+1;
            }else{
                ans=min(nums[mid],ans);
                right = mid-1;
            }
        }
        return ans;
    }
};