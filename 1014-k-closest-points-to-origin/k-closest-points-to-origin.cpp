class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<double,int>> answer;
        for(int i = 0;i<points.size();i++){
            double temp  = pow(points[i][0],2) +pow(points[i][1],2);
            answer.insert(make_pair(temp,i));
        }
        vector<vector<int>> ans;
        auto it = answer.begin();
        for(int i = 0;i<k;i++){
            ans.push_back(points[it->second]);
            it++;
        }
        return ans;
    }
};