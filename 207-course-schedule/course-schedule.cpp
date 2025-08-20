class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
         queue<int> q;
       
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
        vector<int> topo;
        while(!q.empty()){
            int front = q.front();
            topo.push_back(front);
            q.pop();
            for(int u:adj[front]){
                indegree[u]--;
                if(indegree[u]==0) q.push(u);
            }
        }
        cout<<topo.size();
        if(topo.size()==numCourses){
            return true;
        }
        return false;
    }
};