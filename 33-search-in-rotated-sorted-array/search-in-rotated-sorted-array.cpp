#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Зорилтот тоо олдвол шууд индексийг буцаана
            if (nums[mid] == target) {
                return mid;
            }

            // 1. Зүүн тал нь эрэмбэлэгдсэн эсэхийг шалгах
            if (nums[left] <= nums[mid]) {
                // target нь зүүн эрэмбэлэгдсэн хэсэг дотор багтаж байгаа эсэх
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // 2. Үгүй бол баруун тал нь гарцаагүй эрэмбэлэгдсэн байна
            else {
                // target нь баруун эрэмбэлэгдсэн хэсэг дотор багтаж байгаа эсэх
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1; // Олдохгүй бол -1 буцаана
    }
};