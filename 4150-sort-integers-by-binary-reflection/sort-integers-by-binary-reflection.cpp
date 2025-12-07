class Solution {
public:
    int reflection(int n) {
        int i = 31 - __builtin_clz(n);
        int ans = 0;
        for (int j = 0; j <= i; j++) {
            if (n & (1 << j)) {
                ans |= (1 << (i - j));
            }
        }
        return ans;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> reflections(n);
        for (int i = 0; i < n; i++) {
            reflections[i] = {reflection(nums[i]), nums[i]};
        }
        sort(reflections.begin(), reflections.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = reflections[i].second;
        }
        return ans;
    }
};