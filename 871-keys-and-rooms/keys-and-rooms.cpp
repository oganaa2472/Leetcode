class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it:rooms[front]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        for(int i =0;i<n;i++){
            if(vis[i]==false) return false;
        }
        return true;
    }
};