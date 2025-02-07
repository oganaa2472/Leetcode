class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> m,m1;
        vector<int> answer;
        for(auto q:queries){
            int x = q[0];
            int y = q[1];
            if(m1.find(x)!=m1.end()){
                int prevColor = m1[x];
                m[prevColor]--;
                if(m[prevColor]==0) m.erase(prevColor);
            }
            m1[x] = y;
            m[y]++;
            answer.push_back(m.size());
        }
        return answer;
    }
};