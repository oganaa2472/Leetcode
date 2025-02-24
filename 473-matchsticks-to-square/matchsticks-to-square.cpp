class Solution {
public:

    int target;
    unordered_map<int, bool> dp;
    vector<int> nums;
    bool solve(int mask, int currSum) {
       if (mask == (1 << nums.size()) - 1) return true; 
       if (dp.count(mask)) return dp[mask]; 
       for (int i = 0; i < nums.size(); i++) {
             if (!(mask & (1 << i))) {
                int newSum = currSum + nums[i];
                if (newSum > target) continue; 
                
                int newMask = mask | (1 << i);
                if (solve(newMask, newSum % target)) return dp[mask] = true;
            }
       }
       return dp[mask] = false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        this->nums = matchsticks;
     
        int totalSum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(totalSum%4!=0) return false;

        target = totalSum/4;
        return solve(0,0);

    }
};