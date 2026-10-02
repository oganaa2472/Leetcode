#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 1. Хайж буй тоо олдсон эсэх
            if (nums[mid] == target) {
                return true;
            }

            // 2. Гол онцлог: Гурван заагч тэнцүү үед аль тал нь эрэмбэтэйг
            // мэдэх боломжгүй тул хоёр захаа хумина
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // 3. Зүүн тал нь эрэмбэлэгдсэн үе
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // 4. Баруун тал нь эрэмбэлэгдсэн үе
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};