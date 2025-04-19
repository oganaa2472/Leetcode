class Solution {
public:
   const int P = 31;            // Prime base
const int MOD = 1e9 + 9;     // Large prime modulus

vector<int> rabinKarp(string const& text, string const& pattern) {
int n = text.size(), m = pattern.size();
long long p_pow = 1;
long long pattern_hash = 0;

// Calculate hash of pattern
for (char c : pattern) {
    pattern_hash = (pattern_hash + (c - 'a' + 1) * p_pow) % MOD;
    p_pow = (p_pow * P) % MOD;
}

vector<long long> prefix_hash(n + 1, 0);
p_pow = 1;

// Prefix hash for text
for (int i = 0; i < n; i++) {
    prefix_hash[i + 1] = (prefix_hash[i] + (text[i] - 'a' + 1) * p_pow) % MOD;
    p_pow = (p_pow * P) % MOD;
}

vector<int> result;

p_pow = 1;
for (int i = 0; i + m <= n; i++) {
    long long current_hash = (prefix_hash[i + m] - prefix_hash[i] + MOD) % MOD;
    long long hash_pattern_scaled = (pattern_hash * p_pow) % MOD;
    if (current_hash == hash_pattern_scaled) {
        result.push_back(i);
    }
    p_pow = (p_pow * P) % MOD;
}

return result;
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> rabinA = rabinKarp(s,a);
        vector<int> rabinB =  rabinKarp(s,b);
        int n = s.size(), m = a.size();


        vector<int> answer;
        int b_ind = 0;
        int b_size = rabinB.size();
        for(auto a_ind :rabinA ){
            auto l = lower_bound(rabinB.begin(),rabinB.end(),a_ind-k)- rabinB.begin();
            auto r = upper_bound(rabinB.begin(),rabinB.end(),a_ind+k) - rabinB.begin()-1;
            if(r-l+1>0) answer.push_back(a_ind);
            
        }
       
        
       
        return answer;
    }
};