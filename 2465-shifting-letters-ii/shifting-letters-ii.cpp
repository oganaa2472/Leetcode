class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> check(s.size() + 1, 0);

        // Apply difference array technique
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            check[start] += (direction == 1) ? 1 : -1;
            check[end + 1] += (direction == 1) ? -1 : 1;
        }

        // Calculate cumulative shifts
        int cumulativeShift = 0;
        for (int i = 0; i < s.size(); i++) {
            cumulativeShift += check[i];
            // Ensure the shift is within [0, 25]
            int effectiveShift = (s[i] - 'a' + cumulativeShift) % 26;
            if (effectiveShift < 0) effectiveShift += 26; // Handle negative shifts
            s[i] = 'a' + effectiveShift;
        }

        return s;
    }
};
