class Solution {
public:
    bool isCheck(int n,vector<vector<int>>& edges,int mid){
        vector<vector<int>> graph(n);
        for(auto& edge:edges){
            if(edge[2]<=mid){
                graph[edge[1]].push_back(edge[0]);
            }
        }
        vector<int> visited(n,false);
        queue<int> q;

        q.push(0);
        visited[0] = true;
        int count = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int child : graph[cur]){
                if(visited[child]==false){
                    visited[child] = true;
                    q.push(child);
                    count++;
                }
            }
        }
        return count==n;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mn = INT_MAX;
        int mx = 0;
        for(int i = 0;i<edges.size();i++){
            mn = min(mn,edges[i][2]);
            mx = max(mx,edges[i][2]);
        }
        int ans = -1;
        int l = mn,h = mx;

        while(l<=h){
            int mid = l+(h-l)/2;
            if(isCheck(n,edges,mid)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};