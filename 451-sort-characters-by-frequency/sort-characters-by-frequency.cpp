class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        cout<<pq.top().first;
        string ans = "";
        while(!pq.empty()){
            pair<int,char> i = pq.top();
            while(i.first--) ans += i.second;
            pq.pop();
        }
        return ans;
    }
};