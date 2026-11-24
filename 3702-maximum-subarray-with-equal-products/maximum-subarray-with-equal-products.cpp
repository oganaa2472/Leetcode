class Solution {
public:
    int maxLength(vector<int>& nums) {
    int n = nums.size();
    int maxLength = 1; 

    for (int i = 0; i < n; ++i) {
        long long prod = 1;
        int currentGCD = nums[i];
        int currentLCM = nums[i];

        for (int j = i; j < n; ++j) {
            prod *= nums[j];
            currentGCD = gcd(currentGCD, nums[j]);
            currentLCM = lcm(currentLCM, nums[j]);

            
            if (prod == (long long)currentLCM * currentGCD) {
                maxLength = max(maxLength, j - i + 1);
            }
            if(prod>1e9) break;
        }
    }

    return maxLength;
    }
};