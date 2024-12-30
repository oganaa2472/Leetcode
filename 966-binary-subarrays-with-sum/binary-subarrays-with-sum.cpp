class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int,int> freq ;
        int ans =0;
        for(int i = 0;i<nums.size();i++){
            sum = sum+nums[i];
            
            if(sum==goal)ans++;
            if(freq[sum-goal]>0){
                ans = ans+freq[sum-goal];
            }
            freq[sum]++;
        }
        return ans;
    }
};