#include <vector>

class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int k = -1; // -1 гэдэг нь бүх бит 1 байгааг илэрхийлнэ (bitwise AND-ийн эхний утга)
        bool isSorted = true;

        for (int i = 0; i < nums.size(); ++i) {
            // Элемент өөрийн байрлалдаа байхгүй бол
            if (nums[i] != i) {
                isSorted = false;
                if (k == -1) {
                    k = nums[i];
                } else {
                    k &= nums[i];
                }
            }
        }

        // Аль хэдийн эрэмбэлэгдсэн бол 0 буцаана
        if (isSorted) {
            return 0;
        }

        return k;
    }
};