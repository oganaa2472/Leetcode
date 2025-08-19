class Solution {
public:
    void dfs(int i, vector<bool>& visited,vector<vector<int>>& rooms){
        visited[i] = true;
        for(auto it : rooms[i]){
            if(!visited[it]) dfs(it,visited,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        
        vector<bool> visited(n,false);
        visited[0] = true;
        dfs(0,visited,rooms);
        for(int i = 0;i<n;i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};