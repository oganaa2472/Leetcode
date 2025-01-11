class Solution {
public:
    int trap(vector<int>& nums) {
         int n = nums.size();
        vector<int> result(n);
        stack<int> sta;
        int ans = 0;
        for(int i = 0;i<n;i++){
            while(!sta.empty()&&nums[i]>nums[sta.top()]){
                int cur = sta.top();
                sta.pop();
                if(sta.empty()) break;
               int diff = i - sta.top() - 1;
                ans = ans + (min(nums[sta.top()], nums[i]) - nums[cur])*diff;
            }
            sta.push(i);
        }
      
        return ans;
    }
};