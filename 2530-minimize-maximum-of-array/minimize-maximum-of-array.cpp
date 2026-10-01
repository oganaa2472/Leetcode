class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        long long left = 0;
        long long right = *max_element(nums.begin(), nums.end());

        auto check = [&](long long mid) {
    long long carry = 0; // Зүүн тийш шилжүүлэх ёстой илүүдэл

    for (int i = n - 1; i >= 1; i--) {
        long long cur = nums[i] + carry;
        if (cur > mid) {
            carry = cur - mid; // mid-ээс давсан хэсгийг зүүн талын nums[i-1]-д үүрүүлнэ
        } else {
            carry = 0; // Хэрэв хүрэхгүй бол энэ нүдэнд зүүнээс ирсэн зүйл шингэж дуусна
        }
    }

    return (nums[0] + carry) <= mid;
};
        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};