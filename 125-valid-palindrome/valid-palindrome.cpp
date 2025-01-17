class Solution {
public:
    bool isCheck(char ch) {
        return !isalnum(ch); // Check if the character is not alphanumeric
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            char ch = tolower(s[i]);
            char c2 = tolower(s[j]);

            if (isCheck(ch)) {
                i++;
            } else if (isCheck(c2)) {
                j--;
            } else {
                if (ch != c2) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
