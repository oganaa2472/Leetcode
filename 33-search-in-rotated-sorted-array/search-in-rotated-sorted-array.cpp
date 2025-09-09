class Solution {
public:
    // 0 , 1 ,2 ,3 ,4, 5 9
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        // 
        while(left<=right){
            int mid = left+(right-left) /2;
            if(nums[mid]==target) return mid;
            if(nums[left]<=nums[mid]){
                if(nums[left]>target||nums[mid]<target){
                    left = mid + 1;
                }else{
                    right = mid-1;
                }
            }else{
                if(nums[right]<target||nums[mid]>target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};