
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> current;
        int left = 0;
        int count=0;
        long long sum = 0;
        long long ans = 0;
        for(int right=0;right<n;right++){
            current[nums[right]]++;
            sum = sum+nums[right];
            count++;
            while(count>k){
                current[nums[left]]--;
                count--;
                if(current[nums[left]]==0){
                    current.erase(nums[left]);
                }
                sum = sum-nums[left];
                left++;
            }
            
            if(count==k&&current.size()==k){
                ans = max(sum,ans);
            }
        }
        return ans;
    }
};