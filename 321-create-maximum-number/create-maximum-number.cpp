class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int t) {
        vector<int> stack;
        int drop = nums.size() - t; // how many digits we can drop
        for(int num : nums) {
            // While current num is bigger than stack top, pop stack
            while(!stack.empty() && drop > 0 && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        // Resize to t elements (in case stack is longer)
        stack.resize(t);
        return stack;
    }
    vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while(i < a.size() || j < b.size()) {
        // Compare lexicographically remaining subsequences
        if(vector<int>(a.begin() + i, a.end()) > vector<int>(b.begin() + j, b.end())) {
            res.push_back(a[i++]);
        } else {
            res.push_back(b[j++]);
        }
    }
    return res;
}
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int m = nums1.size(), n = nums2.size();
        
        // Try all splits: i digits from nums1, k-i digits from nums2
        for(int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> subseq1 = maxSubsequence(nums1, i);
            vector<int> subseq2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(subseq1, subseq2);
            if(candidate > res) res = candidate; // keep the max
        }
        return res;
    }
};