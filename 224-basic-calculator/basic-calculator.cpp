class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        long number = 0;
        int sign = 1; // 1 means positive, -1 means negative

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                // Handle multi-digit numbers
                number = 10 * number + (c - '0');
            } else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (c == '(') {
                // Push the current result and sign to handle the scope
                st.push(result);
                st.push(sign);
                // Reset for the new scope inside ()
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * number;
                number = 0;
                
                // Result = (Result inside bracket * sign before bracket) + result before bracket
                result *= st.top(); // This is the sign
                st.pop();
                result += st.top(); // This is the previous result
                st.pop();
            }
        }
        
        // Add the final number if there's one left
        result += sign * number;
        return result;
    }
};