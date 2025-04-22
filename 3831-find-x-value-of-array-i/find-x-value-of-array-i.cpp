#include <vector>
#include <numeric>

class Solution {
public:
    // Function to find the x-value of the array for each remainder modulo k.
    // The x-value for a given x is the number of contiguous subarrays
    // whose product leaves a remainder of x when divided by k.
    // This function uses the requested signature: vector<long long> resultArray(vector<int>& nums, int k).
    // Note: The standard LeetCode problem uses findXValueOfArrayI and returns vector<int>.
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        // total_counts[r] stores the total number of contiguous subarrays
        // found so far whose product modulo k is equal to r.
        // Using long long as requested by the return type, although int should be sufficient
        // based on problem constraints (counts won't exceed N).
        std::vector<long long> total_counts(k, 0);
        // current_counts[r] stores the number of contiguous subarrays ending
        // at the current index whose product modulo k is equal to r.
        // This is updated as we iterate through the array.
        std::vector<int> current_counts(k, 0);

        // Iterate through each element of the array. The current element nums[j]
        // serves as the potential end of new contiguous subarrays.
        for (int j = 0; j < n; ++j) {
            // Create a new counts array to store the counts for subarrays ending at index j.
            // This will become the new current_counts after processing index j.
            std::vector<int> new_counts(k, 0);

            // The subarray consisting of only the current element nums[j] is a valid
            // contiguous subarray ending at j. Its product is nums[j], and its
            // remainder modulo k is nums[j] % k.
            new_counts[nums[j] % k]++;

            // Now, consider extending the contiguous subarrays that ended at the previous index (j-1).
            // If a subarray ending at j-1 had a product modulo k of 'r' (meaning current_counts[r] > 0),
            // extending this subarray to include nums[j] will form a new contiguous subarray
            // ending at index j. The product of this new subarray modulo k will be
            // (r * nums[j]) % k.
            for (int r = 0; r < k; ++r) {
                if (current_counts[r] > 0) {
                    // Calculate the new remainder. It's crucial to cast 'r' to long long
                    // before multiplying by nums[j] to prevent potential integer overflow,
                    // as nums[j] can be large (up to 10^9).
                    long long new_remainder = (static_cast<long long>(r) * nums[j]) % k;
                    // Add the count of subarrays ending at j-1 with remainder r
                    // to the new count for the combined remainder.
                    new_counts[new_remainder] += current_counts[r];
                }
            }

            // After considering all subarrays ending at j, update current_counts
            // to reflect these new counts.
            current_counts = new_counts;

            // Add the counts of all contiguous subarrays ending at index j to the total counts.
            // Each such subarray corresponds to a valid way of removing a non-overlapping
            // prefix and suffix to leave this subarray.
            for (int r = 0; r < k; ++r) {
                total_counts[r] += current_counts[r];
            }
        }

        // After iterating through all elements, total_counts[x] will hold the
        // total number of contiguous subarrays whose product modulo k is x.
        // This is the required x-value for each x from 0 to k-1.
        return total_counts;
    }
};
