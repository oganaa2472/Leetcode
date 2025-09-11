#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        // Sort intervals based on their end times
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        
        int prev_end = intervals[0][1]; // Initialize with the end of the first interval
        int count = 0; // Count of intervals to remove

        // Iterate from the second interval
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev_end) {
                // Increment the removal count if there is an overlap
                ++count;
            } else {
                // Update the end if there is no overlap
                prev_end = intervals[i][1];
            }
        }

        return count;
    }
};