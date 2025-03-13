class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 1;
        int right = nums.size()-2;
        int n = nums.size();
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while(left<=right){
            int mid = left+(right-left)/2;

           if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;

            // If we are in the left:
            if (nums[mid] > nums[mid - 1]) left = mid + 1;

            // If we are in the right:
            // Or, arr[mid] is a common point:
            else right = mid - 1;
        }
        return -1;

    }
};