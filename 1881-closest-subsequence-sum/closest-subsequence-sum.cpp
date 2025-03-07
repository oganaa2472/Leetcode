class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> a, b;
        
        // Split the array into two halves
        for(int i = 0; i < n / 2; i++) {
            a.push_back(nums[i]);
        }
        for(int i = n / 2; i < n; i++) {
            b.push_back(nums[i]);
        }
        
        vector<int> left, right;

        // Generate subset sums for left part
        for(int i = 0; i < (1 << a.size()); i++) {
            int l = 0;
            for(int j = 0; j < a.size(); j++) {
                if(i & (1 << j)) {  // Correct bitwise operation
                    l += a[j]; 
                }
            }
            left.push_back(l);
        }

        // Generate subset sums for right part
        for(int i = 0; i < (1 << b.size()); i++) {
            int r = 0;
            for(int j = 0; j < b.size(); j++) {
                if(i & (1 << j)) {  // Correct bitwise operation
                    r += b[j]; 
                }
            }
            right.push_back(r);
        }

        // Sort right sums for binary search
        sort(right.begin(), right.end());

        int ans = INT_MAX;

        // Try to find closest pair (s from left, b from right)
        for(int s : left) {
            int l = 0, r = right.size() - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                int sum = s + right[mid];
                ans = min(ans, abs(goal - sum));
                if(ans == 0) return 0;  // Found perfect match
                if(sum < goal) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};
