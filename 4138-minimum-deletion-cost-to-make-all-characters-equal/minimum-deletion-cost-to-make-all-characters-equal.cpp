class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long totalCost = 0;
        vector<long long> mp(26, 0);

        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a'] += cost[i];
            totalCost += cost[i];
        }

        long long maxi = 0;
        for (int i = 0; i < 26; i++) {
            maxi = max(maxi, mp[i]);
        }

        return totalCost - maxi;
    }
};