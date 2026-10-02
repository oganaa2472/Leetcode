#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // left == right болох үед хамгийн бага элементийн индекс дээр зогсоно
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Хамгийн бага тоо баруун талд байна
                left = mid + 1;
            } else {
                // nums[mid] <= nums[right]: mid өөрөө хамгийн бага тоо байх боломжтой
                right = mid;
            }
        }

        return nums[left];
    }
};