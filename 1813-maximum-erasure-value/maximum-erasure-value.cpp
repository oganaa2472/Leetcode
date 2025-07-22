class Solution {
public:                          
    int maximumUniqueSubarray(vector<int>& nums) {
        int right = 0;
        int left = 0; 
        int count = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp ;
        while(right<n&&left<n){
            if(mp[nums[right]]==0){
                count = count + nums[right];
                ans = max(ans,count);
                mp[nums[right]]++;
                right++;
            }else{
                count = count - nums[left];
                mp[nums[left]]--;
                if(nums[left]==0) mp.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};