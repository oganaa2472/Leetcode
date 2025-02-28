class Solution {
public:
    vector<int> nums;
    vector<vector<int>> gcdVal;
    unordered_map<int, int> memo;

    int solve(int mask, int n) {
        if (mask == (1 << n) - 1) return 0; 

        if (memo.count(mask)) return memo[mask]; 

        int bits = __builtin_popcount(mask);
        int k = bits / 2 + 1; 

        int maxScore = 0;

       
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) continue;

            for (int j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) != 0) continue; 

                int newMask = mask | (1 << i) | (1 << j);
                int score = k * gcdVal[i][j] + solve(newMask, n);
                maxScore = max(maxScore, score);
            }
        }
        return memo[mask] = maxScore;

    
    }
    int maxScore(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        gcdVal.resize(n, vector<int>(n, 0));



        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdVal[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        return solve(0, n);
    }
};