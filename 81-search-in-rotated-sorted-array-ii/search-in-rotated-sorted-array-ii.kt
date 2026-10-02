class Solution {
    fun search(nums: IntArray, target: Int): Boolean {
        var left = 0
        var right = nums.size - 1

        while (left <= right) {
            val mid = left + (right - left) / 2

            if (nums[mid] == target) {
                return true
            }

            // ШИНЭ НӨХЦӨЛ: Гурван цэг хоорондоо тэнцүү үед аль тал нь 
            // эрэмбэтэйг мэдэх боломжгүй тул хоёр захаа хумина
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++
                right--
                continue
            }

            // 1. Зүүн тал нь эрэмбэлэгдсэн үе
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            } 
            // 2. Баруун тал нь эрэмбэлэгдсэн үе
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
            }
        }

        return false
    }
}