#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    vector<vector<int>> memo;

    bool isPalindrome(const string &s, int i, int j) {
        if (i > j) return true; // empty substring
        if (i == j) return true; // single char
        if (memo[i][j] != -1) return memo[i][j];

        bool res = (s[i] == s[j]) && isPalindrome(s, i+1, j-1);
        memo[i][j] = res;
        return res;
    }

    int countSubstrings(string s) {
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

