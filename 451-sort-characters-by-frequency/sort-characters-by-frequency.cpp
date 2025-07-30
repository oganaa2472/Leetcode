class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        for(auto ch:s) freq[ch]++;

        priority_queue<pair<int,char>> pq;
        for(auto [ch,cnt]:freq ) pq.push({cnt,ch});
        string answer = "";
        while(!pq.empty()){
            auto [cnt,ch] = pq.top();
            pq.pop();
            for(int i = 0;i<cnt;i++){

                answer+=ch;
            }
        }
        return answer;
    }
};