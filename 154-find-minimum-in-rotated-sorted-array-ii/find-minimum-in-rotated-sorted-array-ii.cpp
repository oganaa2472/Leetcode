#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Бага тоо баруун талд бий
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // Бага тоо mid өөрөө эсвэл зүүн талд бий
                right = mid;
            } else {
                // nums[mid] == nums[right] үед баруун захаас 1 алхам хасна
                right--;
            }
        }

        return nums[left];
    }
};