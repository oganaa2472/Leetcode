class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(),stones.end(),0);

        int target = total/2;
    
        vector<bool> dp(target + 1, false);
        dp[0] = true; // There's always a way to make sum 0, by choosing no stone
        for (int stone : stones) {
            // Traverse backwards to avoid overwriting results needed for this iteration
            for (int j = target; j >= stone; --j) {
                dp[j] = dp[j] || dp[j - stone]; // Check if the current stone can form the sum 
            }
        }
        
         for (int s1 = target; s1 >= 0; --s1) {
            if (dp[s1]) { // Find the largest subset sum less than or equal to totalSum/2
                return total - 2 * s1; // The minimized last stone weight
            }
        }
        
        return 0; 
        
    }
};