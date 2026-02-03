class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int left = 0,right = 0;
        int n = nums.size();
        while(right<n-1){
            int fartest = 0;
            for(int i = left;i<=right;i++){
                fartest = max(i+nums[i],fartest);
            }
            left = right+1;
            right = fartest;
            jumps+=1;
        }
        return jumps;
    }
};