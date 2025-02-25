class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int odd_count = 0, even_count = 1;
        int prefix_sum = 0, result = 0;
        for (int num : arr) {
            prefix_sum += num;
            
            if (prefix_sum % 2 == 0) {
                result = (result + odd_count) % mod;
                even_count++;
            } else {
                result = (result + even_count) % mod;
                odd_count++;
            }
        }
        return result;
    }
};