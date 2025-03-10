class Solution {
public:
       vector<vector<int>> memo;
    vector<int> newCuts;

    int cost(int left, int right) {
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        if (right - left == 1) {
            return 0;
        }
        int ans = INT_MAX;
        for (int mid = left + 1; mid < right; ++mid) {
            int currentCost = cost(left, mid) + cost(mid, right) + newCuts[right] - newCuts[left];
            ans = min(ans, currentCost);
        }
        return memo[left][right] = ans;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        newCuts.resize(m + 2);
        newCuts[0] = 0;
        copy(cuts.begin(), cuts.end(), newCuts.begin() + 1);
        newCuts[m + 1] = n;
        sort(newCuts.begin(), newCuts.end());

        memo.assign(m + 2, vector<int>(m + 2, -1));
        return cost(0, newCuts.size() - 1);
    }
};