class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            } else {  // c == ')'
                if (open > 0) {
                    open--;  // Match the current ')' with a previous '('
                } else {
                    close++;  // No matching '(' for this ')'
                }
            }
        }

        // Total unmatched parentheses is sum of unmatched open and close
        return open + close;
    }
};