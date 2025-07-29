class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int n = nums.size();
        int left = 0;
        int cnt = 0;
        int ans = 0;
        map<int,int> current;
        for(int right=0;right<n;right++){
            cnt++;
            current[nums[right]]++;
            while(cnt!=current.size()){
                current[nums[left]]--;
                if(current[nums[left]]==0){
                    current.erase(nums[left]);
                }
                cnt--;
                left++;
            }
            ans = max(ans,right-left+1);
        }   
        return ans;
    }
};