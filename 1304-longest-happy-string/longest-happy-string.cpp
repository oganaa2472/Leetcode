class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string result="";
        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();
            int n = result.size();

        // If adding ch1 causes three consecutive same characters
            if (n >= 2 && result[n - 1] == ch1 && result[n - 2] == ch1) {
            if (pq.empty()) break; // no valid character left

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                result.push_back(ch2);
                cnt2--;

                if (cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt1, ch1});
            } else {
                result.push_back(ch1);
                cnt1--;

                if (cnt1 > 0) pq.push({cnt1, ch1});
            }
        }
        return result;
    }
};