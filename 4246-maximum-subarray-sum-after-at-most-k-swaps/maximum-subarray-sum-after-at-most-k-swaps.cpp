class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = -150000000LL;

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        multiset<int> candidates, others;

        for(int start = 0; start < n; start++) {
            candidates.clear();
            others.clear();

            for(int i = 0; i < max(0, n - k); i++) {
                others.insert(sorted[i]);
            }

            for(int i = max(0, n - k); i < n; i++) {
                candidates.insert(sorted[i]);
            }

            long long currentSum = 0;

            for(int end = start; end < n; end++) {
                if(!others.empty()) {
                    int val;
                    auto itOther = others.find(nums[end]);

                    if(itOther != others.end()) {
                        val = nums[end];
                        others.erase(itOther);
                    } else {
                        auto itLargestOther = prev(others.end());
                        val = *itLargestOther;
                        others.erase(itLargestOther);
                    }
                    candidates.insert(val);
                }

                auto itLargestCandidate = prev(candidates.end());
                currentSum += *itLargestCandidate;
                candidates.erase(itLargestCandidate);

                ans = max(ans, currentSum);
            }
        }

        return ans;
    }
};