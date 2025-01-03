from collections import defaultdict
import bisect

class Solution:
    def numberOfSubsequences(self, nums: List[int]) -> int:
        ratios = defaultdict(list)

        for p in range(len(nums)):
            for q in range(p + 2, len(nums)):
                ratios[nums[p] / nums[q]].append(q)

        ans = 0
        for k, v in ratios.items():
            ratios[k] = list(sorted(v))

        for r in range(4, len(nums)):
            for s in range(r + 2, len(nums)):
                ratio = nums[s] / nums[r]

                if ratio in ratios:
                    left = 0
                    right = len(ratios[ratio]) - 1

                    while left <= right:
                        mid = (left + right) // 2
                        q = ratios[ratio][mid]
                    
                        if q > r - 2:
                            right = mid - 1
                        else:
                            left = mid + 1

                    ans += max(left, 0)

        return ans