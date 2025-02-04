class Solution {
public:
    int target;
    unordered_map<int, bool> dp; // Memoization (битийн маскаар төлөв хадгалах)

    bool canPartition(vector<int>& nums, int k, int usedMask, int currentSum, int count) {
        if (count == k - 1) return true; // Хэрэв k-1 subset зөв болсон бол сүүлийн subset автоматаар зөв

        if (dp.count(usedMask)) return dp[usedMask]; // Хэрэв өмнө нь тооцоолсон бол буцаана

        if (currentSum == target) 
            return dp[usedMask] = canPartition(nums, k, usedMask, 0, count + 1); // Дараагийн subset рүү шилжих

        for (int i = 0; i < nums.size(); i++) {
            if (!(usedMask & (1 << i)) && currentSum + nums[i] <= target) { // Битийн маск шалгах
                if (canPartition(nums, k, usedMask | (1 << i), currentSum + nums[i], count))
                    return dp[usedMask] = true;
            }
        }
        return dp[usedMask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false; // Хэрэв нийт нийлбэр k-д хуваагдахгүй бол боломжгүй

        target = sum / k;
        // sort(nums.rbegin(), nums.rend()); // Том тоонуудыг эхэнд нь авч optimization хийх

        return canPartition(nums, k, 0, 0, 0);
    }
};
