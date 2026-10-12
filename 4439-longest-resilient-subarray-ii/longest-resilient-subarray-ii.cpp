class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans=1,n=nums.size(),i=0,j=0;
        long long sum=0;
        unordered_map<int,int>mp;
        while(j<n){
           mp[nums[j]%k]++;
            sum+=nums[j];
            while(mp.size()>1){
               mp[nums[i]%k]--;
                if(mp[nums[i]%k]==0) mp.erase(nums[i]%k);
                sum-=nums[i];
                i++;
                
            }
            auto num=mp.begin()->first;
            if((sum-num)%k==0)
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};