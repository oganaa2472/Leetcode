class Solution {
    HashMap<String, Integer> dp;

    public int countSequences(int[] nums, long k) {
        dp = new HashMap<>();
        return solve(nums, k, 1L, 1L, 0);
    }

    private int solve(int[] nums, long k, long num, long den, int index) {
        // Base Case: All numbers processed
        if (index == nums.length) {
            return (num == k * den) ? 1 : 0;
        }

        // Simplify fraction to keep numbers small and state unique
        long g = gcd(num, den);
        num /= g;
        den /= g;

        String key = num + " " + den + " " + index;
        if (dp.containsKey(key)) {
            return dp.get(key);
        }

        int count = 0;

        // Choice 1: Multiply current number
        count += solve(nums, k, num * nums[index], den, index + 1);

        // Choice 2: Divide by current number
        count += solve(nums, k, num, den * nums[index], index + 1);

        // Choice 3: Ignore current number
        count += solve(nums, k, num, den, index + 1);

        dp.put(key, count);
        return count;
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}