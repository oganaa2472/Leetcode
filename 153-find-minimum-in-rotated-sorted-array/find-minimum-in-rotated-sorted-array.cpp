class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(nums.size()==1) return nums[0];
        int ans = INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
            ans=min(nums[mid],ans);
          
           if(nums[left]<=nums[mid]){
                if(nums[left]<nums[right]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
               
            }else{
                if(nums[left]<nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return ans;
    }
};