class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (r - l > 2) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (arr[m1] < arr[m2]) {
                l = m1;
            } else {
                r = m2;
            }
        }
        // Final linear check for max
        int peak = l;
        for (int i = l+1; i <= r; ++i)
            if (arr[i] > arr[peak])
                peak = i;
        return peak;
    }
};