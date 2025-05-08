class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double,int>> point_index;
        priority_queue<pair<double,int>> pq;
        for(int i = 0;i<points.size();i++){
            double temp  = pow(points[i][0],2) +pow(points[i][1],2);
            point_index.push_back(make_pair(temp,i));
        }//O(n)
        int n = points.size();
        for(int i = 0;i<k;i++){
            pq.push(point_index[i]);
        }        
        for(int i = k;i<n;i++) {
            pair<double,int> cur = pq.top();
            if(cur.first>point_index[i].first){
                pq.pop();
                pq.push(point_index[i]);
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        // cout<<pq.top().first<<" "<<pq.top().second;
        return result;
    }
};