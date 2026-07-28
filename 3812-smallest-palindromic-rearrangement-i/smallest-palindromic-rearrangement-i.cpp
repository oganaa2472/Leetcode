class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
         int odd = 0;
         char mid = 0;
         string half = "";


    for (auto& entry : freq) {
        char ch = entry.first;
        int cnt = entry.second;

        if (cnt % 2 == 1) {
            odd++;
            mid = ch;
        }

        half += string(cnt / 2, ch); 
    }

  
        if (odd > 1) {
            return "";
        }
    
      
        string result = half;
        if (mid) {
            result += mid;
        }
    
        reverse(half.begin(), half.end());
        result += half;
    
        return result;

    }
};