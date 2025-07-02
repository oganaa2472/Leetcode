class Solution {
public:
    int binary_search(int l,int r,vector<int>& nums,int target){
        if(l>r) return -1;
        int m = l+(r-l)/2;
        if(nums[m]==target) return m;
        if(nums[m]<target){
            return  binary_search(m+1,r,nums,target);
        }
        return binary_search(l,m-1,nums,target);
    }
    int search(vector<int>& nums, int target) {
        return binary_search(0,nums.size()-1,nums,target);
        int left= 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left<=right){
            int mid = (left+right);
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return -1;
    }
};