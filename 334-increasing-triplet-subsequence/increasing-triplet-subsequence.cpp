class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> tails;

        for (int x : nums) {
            // find position to replace using binary search
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end())
                tails.push_back(x);   // extend LIS
            else
                *it = x;              // replace with smaller tail
        }

    return (int)tails.size()>=3;
    }
};