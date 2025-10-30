class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i = 0;i<n;i++){
            int cur = nums[i]==0?-1:nums[i];
            prefix[i+1] = prefix[i]+cur; 
        }
        map<int,int> mp;
        // mp[0] = 1;
        int ans = 0;
        for(int i = 0;i<=n;i++){
            if(mp.count(prefix[i])){
                ans =max(ans,i-mp[prefix[i]]);
            }else{
                mp[prefix[i]] = i; 
            }

        }
        return ans;
    }
};