class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n), next(n);
        stack<int> s;

        // Previous Smaller Element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for next pass
        while (!s.empty()) s.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate contribution
        long long result = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long contrib = (left * right) % mod * arr[i] % mod;
            result = (result + contrib) % mod;
        }

        return result;
    }
};
