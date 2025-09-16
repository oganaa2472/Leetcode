class Solution {
public:
   
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
    
    // Use a boolean array to quickly check if a number exists
    vector<bool> exists(maxVal + 1, false);
    for (int x : nums) exists[x] = true;

    int ans = 0;

    // Try each number g as a candidate GCD
    for (int g = 1; g <= maxVal; g++) {
        int currentGCD = 0;

        // Look at all multiples of g
        for (int multiple = g; multiple <= maxVal; multiple += g) {
            if (exists[multiple]) {
                if (currentGCD == 0)
                    currentGCD = multiple;
                else
                    currentGCD = __gcd(currentGCD, multiple);
            }
        }

        // If the GCD of multiples equals g, g is valid
        if (currentGCD == g) ans++;
    }

    return ans;
    }
};