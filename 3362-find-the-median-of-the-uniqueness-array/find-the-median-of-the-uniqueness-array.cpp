class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long) n * (n + 1) / 2;
        auto atmost = [&](int k) {
            long long res = 0;
            unordered_map<int, int> count;
            for (int i = 0, j = 0; j < n; j++) {
                count[nums[j]]++;
                while(count.size() > k) {
                    if (--count[nums[i]] == 0){
                        count.erase(nums[i]);
                    }
                    i++;
                }
                res += j - i + 1;
            }
            return res;
        };
        int left = 1, right = unordered_set<int>(nums.begin(), nums.end()).size();
        while (left < right) {
            int k = (left + right) / 2;
            if (atmost(k) * 2 >= total)
                right = k;
            else
                left = k + 1;
        }
        return left;

    }
};