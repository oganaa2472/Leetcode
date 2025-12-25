class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxPointsCount = 0;
        if(n<=2) return n;

        for(int i = 0;i<n;i++){
            unordered_map<string,int> slopeMap;
            int localMax = 0 ;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int common = __gcd(dx,dy);
                dx=dx/common;
                dy=dy/common;
                string slope = to_string(dy) + "/" + to_string(dx);
                slopeMap[slope]++;
                localMax = max(localMax, slopeMap[slope]);
            }
            maxPointsCount = max(maxPointsCount, localMax + 1);

        }
        return maxPointsCount;
    }
};