class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var left = 0
        var right = nums.size - 1

        while (left <= right) {
            val mid = left + (right - left) / 2

            // 1. Зорилтот тоо яг олдсон эсэх
            if (nums[mid] == target) {
                return mid
            }

            // 2. Зүүн хагас нь эрэмбэлэгдсэн эсэхийг шалгах
            if (nums[left] <= nums[mid]) {
                // target тоо зүүн эрэмбэлэгдсэн завсарт байгаа эсэх
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            } 
            // 3. Үгүй бол баруун хагас нь заавал эрэмбэлэгдсэн байна
            else {
                // target тоо баруун эрэмбэлэгдсэн завсарт байгаа эсэх
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
            }
        }

        return -1 // Олдохгүй бол -1 буцаана
    }
}