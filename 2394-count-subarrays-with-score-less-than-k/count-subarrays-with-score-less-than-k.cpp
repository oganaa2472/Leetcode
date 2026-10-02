
class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0; // Overflow-оос сэргийлж long long
        int left = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            sum += nums[right]; // Баруун захаар шинэ элементээ оруулна

            // Оноо нь k-аас их буюу тэнцүү байвал зүүн захаа хумина
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }

            // right индексээр төгссөн хүчинтэй бүх дэд массивуудыг тоолно
            ans += (right - left + 1);
        }

        return ans;
    }
};