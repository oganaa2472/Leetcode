class Solution {
public:
    const long long P = 31, M = 1e9 + 9;
    vector<int> findMatch(const string& s, const string& t) {
        // base case
        if (s.size() < t.size()) return {};

        // pre-compute powers
        vector<long long> p(s.size());
        p[0] = 1LL;
        for (int i = 1; i < s.size(); i++) p[i] = (p[i - 1] * P) % M;

        // calculate the hash value for the string `t`
        long long hash_t = 0LL;
        for (int i = 0; i < t.size(); i++) hash_t = (hash_t + (t[i] - 'a') * p[i]) % M;

        // calculate the prefix hash values for the string `s`
        vector<long long> hash_s(s.size() + 1, 0);
        for (int i = 0; i < s.size(); i++) hash_s[i + 1] = (hash_s[i] + (s[i] - 'a') * p[i]) % M;

        // find the indices in `s` that contain string `t`
        vector<int> indices;
        for (int i = 0; (i + t.size()) <= s.size(); i++) {
            long long hash = (hash_s[i + t.size()] + M - hash_s[i]) % M;
            if (hash == ((hash_t * p[i]) % M)) indices.push_back(i);
        }
        return indices;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> matchA = findMatch(s, a);
        vector<int> matchB = findMatch(s, b);

        // find the index [i, j] meets the conditions using binary search
        vector<int> result;
        for (auto& i : matchA) {
            auto it = lower_bound(matchB.begin(), matchB.end(), i - k);
            if ((it != matchB.end()) && (abs(*it - i) <= k)) result.push_back(i);
        }
        return result;
    }
};