class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int len = 0;
        int answer = 0;
        for(int right = 0;right<nums.size();right++){
            int cur = nums[right];
            if(cur==0) len++;
            while(len>k){
                if(nums[left]==0){
                    len--;
                }
                left++;
            }
            answer = max(right-left+1,answer);
        }
        return answer;
    }
};