#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>
#include <set>

using namespace std;

// Helper function to calculate max Manhattan distance excluding one point
long long calculateMaxManhattanDistance(const vector<vector<int>>& points, int excluded_idx) {
    long long max_sum = LLONG_MIN;
    long long min_sum = LLONG_MAX;
    long long max_diff = LLONG_MIN;
    long long min_diff = LLONG_MAX;

    for (int i = 0; i < points.size(); ++i) {
        if (i == excluded_idx) {
            continue;
        }
        long long current_sum = (long long)points[i][0] + points[i][1];
        long long current_diff = (long long)points[i][0] - points[i][1];

        max_sum = max(max_sum, current_sum);
        min_sum = min(min_sum, current_sum);
        max_diff = max(max_diff, current_diff);
        min_diff = min(min_diff, current_diff);
    }

    return max(max_sum - min_sum, max_diff - min_diff);
}

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();

        // Handle base case where removing one point leaves < 2 points
        if (n <= 2) {
             return 0; // Removing one point leaves 1 or 0 points, max distance is 0
        }


        // O(N) pass to find 1st/2nd max/min for sums and diffs and their indices
        long long max1_sum = LLONG_MIN, idx_max1_sum = -1;
        long long max2_sum = LLONG_MIN, idx_max2_sum = -1; // 2nd largest sum

        long long min1_sum = LLONG_MAX, idx_min1_sum = -1;
        long long min2_sum = LLONG_MAX, idx_min2_sum = -1; // 2nd smallest sum

        long long max1_diff = LLONG_MIN, idx_max1_diff = -1;
        long long max2_diff = LLONG_MIN, idx_max2_diff = -1; // 2nd largest diff

        long long min1_diff = LLONG_MAX, idx_min1_diff = -1;
        long long min2_diff = LLONG_MAX, idx_min2_diff = -1; // 2nd smallest diff


        for (int i = 0; i < n; ++i) {
            long long current_sum = (long long)points[i][0] + points[i][1];
            long long current_diff = (long long)points[i][0] - points[i][1];

            // Update max sums
            if (current_sum > max1_sum) {
                max2_sum = max1_sum; idx_max2_sum = idx_max1_sum;
                max1_sum = current_sum; idx_max1_sum = i;
            } else if (current_sum > max2_sum) { // No need for i != idx_max1_sum due to structure
                max2_sum = current_sum; idx_max2_sum = i;
            }

            // Update min sums
            if (current_sum < min1_sum) {
                min2_sum = min1_sum; idx_min1_sum = idx_min1_sum;
                min1_sum = current_sum; idx_min1_sum = i;
            } else if (current_sum < min2_sum) { // No need for i != idx_min1_sum
                min2_sum = current_sum; idx_min2_sum = i;
            }

            // Update max diffs
            if (current_diff > max1_diff) {
                max2_diff = max1_diff; idx_max2_diff = idx_max1_diff;
                max1_diff = current_diff; idx_max1_diff = i;
            } else if (current_diff > max2_diff) { // No need for i != idx_max1_diff
                max2_diff = current_diff; idx_max2_diff = i;
            }

            // Update min diffs
            if (current_diff < min1_diff) {
                min2_diff = min1_diff; idx_min1_diff = idx_min1_diff;
                min1_diff = current_diff; idx_min1_diff = i;
            } else if (current_diff < min2_diff) { // No need for i != idx_min1_diff
                min2_diff = current_diff; idx_min2_diff = i;
            }
        }

        // Candidate indices to remove are those achieving the 1st/2nd extremes
        set<int> candidate_indices;
        candidate_indices.insert(idx_max1_sum);
        candidate_indices.insert(idx_min1_sum);
        candidate_indices.insert(idx_max1_diff);
        candidate_indices.insert(idx_min1_diff);
        // We only need the 1st extremes because removing a 2nd extreme point
        // will not change the max distance determined by the 1st extremes unless
        // one of the 1st extremes is removed. The new max distance is determined
        // by some pair of points, where at least one was an original 1st extreme
        // or the original 2nd extreme that becomes the new 1st.
        // The critical points whose removal can reduce the max distance are precisely
        // the points contributing to the original max distance (the 4 extreme points).
        // So, removing *any* of these 4 points is what we must check.
        // The set of indices to check is {idx_max1_sum, idx_min1_sum, idx_max1_diff, idx_min1_diff}.

        // Calculate the maximum Manhattan distance for each candidate removal
        long long min_overall_max_distance = LLONG_MAX;

        for (int excluded_idx : candidate_indices) {
            min_overall_max_distance = min(min_overall_max_distance, calculateMaxManhattanDistance(points, excluded_idx));
        }

        return min_overall_max_distance;
    }
};