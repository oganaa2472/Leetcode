class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        vector<int> left_part(nums.begin(), nums.begin() + half);
        vector<int> right_part(nums.begin() + half, nums.end());

        vector<int> left, right;

        // Generate all subset sums for the left half
        for(int i = 0; i < (1 << left_part.size()); i++) {
            int sum = 0;
            for(int j = 0; j < left_part.size(); j++) {
                if(i & (1 << j)) {  // Corrected bitwise check
                    sum += left_part[j];
                }
            }
            left.push_back(sum);
        }

        // Generate all subset sums for the right half
        for(int i = 0; i < (1 << right_part.size()); i++) {
            int sum = 0;
            for(int j = 0; j < right_part.size(); j++) {
                if(i & (1 << j)) {  // Corrected bitwise check
                    sum += right_part[j];
                }
            }
            right.push_back(sum);
        }

        // Sort right subset sums for binary search
        sort(right.begin(), right.end());

        int ans = INT_MAX;

        // Find the closest sum using binary search
        for(int s : left) {
            int target = goal - s;
            auto it = lower_bound(right.begin(), right.end(), target);
            
            if(it != right.end()) {
                ans = min(ans, abs(goal - (s + *it)));  // Case when found or just larger
            }
            if(it != right.begin()) {
                it--;
                ans = min(ans, abs(goal - (s + *it)));  // Case when just smaller
            }
        }

        return ans;
    }
};
