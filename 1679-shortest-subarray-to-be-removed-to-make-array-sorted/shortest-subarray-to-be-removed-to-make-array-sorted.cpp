class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int n = arr.size();

        // Зүүн талаас non-decreasing prefix олно
        int left = 0;

        while (left + 1 < n &&
               arr[left] <= arr[left + 1]) {
            left++;
        }

        // Бүх массив non-decreasing
        if (left == n - 1)
            return 0;

        // Баруун талаас non-decreasing suffix олно
        int right = n - 1;

        while (right > 0 &&
               arr[right - 1] <= arr[right]) {
            right--;
        }

        // Зөвхөн suffix эсвэл prefix устгах
        int ans = min(n - left - 1, right);

        // Prefix + suffix холбож үзнэ
        int i = 0;
        int j = right;

        while (i <= left && j < n) {

            if (arr[i] <= arr[j]) {

                // i ба j-ийн хоорондох хэсгийг устгана
                ans = min(ans, j - i - 1);

                i++;

            } else {

                j++;
            }
        }

        return ans;
    }
};