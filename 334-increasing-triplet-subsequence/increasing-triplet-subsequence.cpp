class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                // Found a new minimum value
                first = num;
            } else if (num <= second) {
                // Found a number larger than `first` but smaller than `second`
                second = num;
            } else {
                // Found a number larger than both `first` and `second`
                return true;
            }
        }
        return false;
    }
};