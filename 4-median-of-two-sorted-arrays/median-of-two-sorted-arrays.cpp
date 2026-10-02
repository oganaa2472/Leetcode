#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Байнга богино массив дээр нь binary search хийнэ
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int half = (m + n + 1) / 2;

        while (left <= right) {
            int i = left + (right - left) / 2; // nums1-ээс авах тоо
            int j = half - i;                  // nums2-оос авах тоо

            // Захын элементүүдийг тодорхойлох (хязгаараас давбал хязгааргүй утга өгнө)
            int a_left  = (i == 0) ? INT_MIN : nums1[i - 1];
            int a_right = (i == m) ? INT_MAX : nums1[i];
            int b_left  = (j == 0) ? INT_MIN : nums2[j - 1];
            int b_right = (j == n) ? INT_MAX : nums2[j];

            // Зөв хуваалт мөн эсэхийг шалгах
            if (a_left <= b_right && b_left <= a_right) {
                // Сондгой үед
                if ((m + n) % 2 == 1) {
                    return std::max(a_left, b_left);
                }
                // Тэгш үед
                return (std::max(a_left, b_left) + std::min(a_right, b_right)) / 2.0;
            } 
            else if (a_left > b_right) {
                // nums1-ээс хэт олон элемент авсан тул зүүн тийш хумина
                right = i - 1;
            } 
            else {
                // nums2-оос хэт олон элемент авсан тул nums1-ээс авах тоог ихэсгэнэ
                left = i + 1;
            }
        }

        return 0.0;
    }
};