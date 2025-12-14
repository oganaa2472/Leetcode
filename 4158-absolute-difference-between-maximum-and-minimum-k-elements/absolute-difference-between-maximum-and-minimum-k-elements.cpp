class Solution {
public:
    int absDifference(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0, j = arr.size() - 1; i < k; i++, j--) {
            ans += -arr[i] + arr[j];
        }
        return ans;
    }
};
