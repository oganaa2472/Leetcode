class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto it:nums){
            freq[it]++;
        }
        int ans = 0;
        for(auto [val,cnt]:freq){
            if(cnt%k==0){
                ans+=(val*cnt);
            }
        }
        return ans;
    }
};