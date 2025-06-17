class Solution {
public:
    map<pair<int, int>, int> dp;

    int solve(int i, int sum, vector<int>& rewardValues) {
        int n = rewardValues.size();
        if (i == n) return 0;

        auto key = make_pair(i, sum);
        if (dp.count(key)) return dp[key];

        int exclude = solve(i + 1, sum, rewardValues);
        int include = 0;

        if (rewardValues[i] > sum) {
            include = rewardValues[i] + solve(i + 1, sum + rewardValues[i], rewardValues);
        }

        return dp[key] = max(include, exclude);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<bool> dp(200001,false);
        dp[0] = true;
        int maxReward = 0;
        for(int r:rewardValues){
            for(int i = maxReward;i>=0;i--){
                if(dp[i]&&r>i){
                    dp[i+r] = true;
                    maxReward = max(i+r,maxReward);
                }
            }
        }
        for (int i = 200000; i >= 0; --i) {
            if (dp[i]) return i;
        }
        return 0;
    }
};
