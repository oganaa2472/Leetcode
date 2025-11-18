class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int left = 0,right = 0;
        int n = nums.size();
        while(right<n-1){
            int fartest = 0;
            for(int i = left;i<right+1;i++){
                fartest = max(fartest,i+nums[i]);
            }
            left = right+1;
            right = fartest;
            res+=1;
        }
        return res;
    }
};