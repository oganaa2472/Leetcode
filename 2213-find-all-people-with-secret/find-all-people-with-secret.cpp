class Solution {
public:
   
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_set<int> secret {0,firstPerson};
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];
});

        int i = 0;
        int m = meetings.size();
        while(i<m){
            int time = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            int j = i;
            while(j<m&&meetings[j][2] == time){
                int x = meetings[j][0];
                int y = meetings[j][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                j++;
            }
            queue<int> q;
            unordered_set<int> visited;
            for(auto& [u,v]:graph){
                if(secret.count(u)){
                    q.push(u);
                    visited.insert(u);
                }
            }
            while(!q.empty()){
                int u = q.front();q.pop();
                for(auto v:graph[u]){
                    secret.insert(v);
                    if(!visited.count(v)){
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
            i = j;
        }
        return vector<int>(secret.begin(),secret.end());
    }
};