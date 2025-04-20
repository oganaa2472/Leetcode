class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0 , n = answers.size();
        unordered_map <int,int> freq;
        for(int &i : answers)
            if(++freq[i] == i + 1)
                ans += i + 1 , freq.erase(i);
        for(auto &[n , _ ] : freq)
                ans += (n + 1);
        return ans;
    }
};