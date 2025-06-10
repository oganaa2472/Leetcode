class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
    for (char ch : s) {
        freq[ch]++;
    }

    vector<int> evens, odds;
    for (auto [ch, cnt] : freq) {
        if (cnt % 2 == 0) evens.push_back(cnt);
        else odds.push_back(cnt);
    }

    if (evens.empty() || odds.empty()) return 0;

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());

    int maxDiff =(odds.back() - evens.front());
    return maxDiff;
    }
};