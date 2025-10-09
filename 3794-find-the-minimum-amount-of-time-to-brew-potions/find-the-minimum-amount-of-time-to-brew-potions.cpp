class Solution {
public:
    typedef long long ll;
    ll minTime(vector<int>& skill, vector<int>& mana) {
        vector<ll> dp(skill.size() + 1, 0);
        for (int i = 0; i < mana.size(); i++) {
            ll curr = 0;
            for (int j = 1; j <= skill.size(); j++) {
                curr += (skill[j - 1] * mana[i]);
                dp[j] = max(dp[j - 1], (dp[j] + mana[i] * skill[j - 1] - curr));
            }
            dp[0] = dp[skill.size()];
            for (int j = 1; j <= skill.size(); j++) dp[j] = dp[j - 1] + mana[i] * skill[j - 1];
        }
        return dp[skill.size()];
    }
};
//mana->potions
//skills->wizard
//bigger (minimize gap without overlap)