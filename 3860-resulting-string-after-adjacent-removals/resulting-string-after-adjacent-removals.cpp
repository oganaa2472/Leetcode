class Solution {
public:
    bool isConsecutive(char a, char b) {
    int diff = abs(a - b);
    return diff == 1 || diff == 25;
}
    string resultingString(string s) {
        stack<char> st;

    for (char c : s) {
        if (!st.empty() && isConsecutive(st.top(), c)) {
            st.pop(); // remove the pair
        } else {
            st.push(c);
        }
    }

   
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;

    }
};