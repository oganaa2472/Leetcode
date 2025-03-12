class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]==nums[mid+1]){
                if((mid-left)%2==1){
                    right = mid-1;
                }else{
                    left = mid+2;
                }
            }else{
                mid=mid-1;
                if(nums[mid]==nums[mid+1]){
                    if((mid-left)%2==1){
                        right = mid-1;
                    }else{
                        left = mid+2;
                    }
                }
                else{
                    return nums[mid+1];
                }
            }
        }
        return nums[left];
    }
};