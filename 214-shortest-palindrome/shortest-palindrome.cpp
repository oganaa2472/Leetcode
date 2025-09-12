class Solution {
public:
    string shortestPalindrome(string s) {
        const long long base = 29, mod = 1e9+7;
    int n = s.size();

    long long hash_f = 0, hash_b = 0, power = 1;
    int best = -1; // longest palindromic prefix

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a' + 1;

        // forward hash (normal)
        hash_f = (hash_f * base + c) % mod;

        // backward hash (reverse)
        hash_b = (hash_b + power * c) % mod;

        if (hash_f == hash_b) best = i; // palindrome prefix

        power = (power * base) % mod;
    }

    // suffix that is not palindrome prefix
    string add = s.substr(best + 1);
    reverse(add.begin(), add.end());
    return add + s;

    }
};