class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1,mid;
        int ans1 = 0,ans2=0;
        while(start<=end){
            mid = (end-start)/2+start;
            if(nums[mid]<0){
                ans1 = mid+1;
                start = mid+1;
            }else {
                end = mid -1;
            }
        }
        start = 0,end = nums.size()-1;
        while(start<=end){
            mid = (end-start)/2+start;
            if(nums[mid]>0){
                ans2 = nums.size()-mid;
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return max(ans1,ans2);
    }
};