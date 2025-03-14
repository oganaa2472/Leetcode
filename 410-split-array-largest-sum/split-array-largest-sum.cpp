class Solution {
public:
    int k;
    vector<int> nums;
    bool splitNum(int mid){
        int day = 1;
        int c=0;
        for(int i = 0;i<nums.size();i++){
            c = c+nums[i];
            if(c>mid){
                day++;
                c=nums[i];
            }
        }
        return day<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int right = accumulate(nums.begin(),nums.end(),0);
        int left = *max_element(nums.begin(),nums.end());
        this->k = k;
        this->nums = nums;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(splitNum(mid)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};