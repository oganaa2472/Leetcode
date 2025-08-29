class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;

        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[left]<=nums[mid]){
                if(nums[mid] < target || target<nums[left]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }else{
                if(target<nums[mid]||target>nums[right]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
                
            }
        }
        return -1;
    }
};