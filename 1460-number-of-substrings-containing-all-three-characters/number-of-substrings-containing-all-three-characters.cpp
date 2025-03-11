class Solution {
public:
 
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int count = 0;
        unordered_map<char, int> charCount;

         while (right < n) {
        charCount[s[right]]++;
       
        while (charCount['a'] > 0 && charCount['b'] > 0 && charCount['c'] > 0) {
            count += n - right;
            charCount[s[left]]--; 
            left++;
        }

        right++;
    }

    return count;

    }
};