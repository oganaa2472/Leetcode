class Solution {
public:
    long long countValidSubstrings(string s) {
       long long ans = 0;
    int left = 0;
    int n = s.size();

    for (int right = 0; right < n; right++) {

        // Check whether the last 3 characters are "abc"
        if (right >= 2 &&
            s[right - 2] == 'a' &&
            s[right - 1] == 'b' &&
            s[right] == 'c') {

            left = right - 1;
        }

        ans += right - left + 1;
    }
    return ans;
    }
};