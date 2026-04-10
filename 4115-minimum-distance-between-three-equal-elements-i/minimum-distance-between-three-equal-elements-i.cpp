class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        int res = INT_MAX;
        for (auto& p : m) {
            auto& v = p.second;
            if (v.size() < 3) continue;
            for (int i = 0; i < v.size() - 2; i++) {
                res = min(res, (v[i + 2] - v[i]) + (v[i + 1] - v[i]) + (v[i + 2] - v[i + 1]));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};