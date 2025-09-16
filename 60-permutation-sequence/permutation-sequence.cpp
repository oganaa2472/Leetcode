class Solution {
public:
    string getPermutation(int n, int k) {
         vector<int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);

    vector<int> fact(n, 1);
    for (int i = 1; i < n; i++) fact[i] = fact[i-1] * i;

    k--; // make k zero-indexed
    string ans = "";
    for (int i = n; i >= 1; i--) {
        int idx = k / fact[i-1];
        ans += to_string(nums[idx]);
        nums.erase(nums.begin() + idx);
        k %= fact[i-1];
    }
    return ans;
    }
};