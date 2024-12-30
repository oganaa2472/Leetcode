class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;

        int n = nums.size();
        unordered_map<int,int> freq;
        int ans = 0;
        freq[0] = 1;
        for(int i = 0;i<n;i++){
            sum+=nums[i]%k;
            sum=(sum+k)%k;
            ans +=freq[sum];
            freq[sum]++;
            
        }
        return ans;
    }
};