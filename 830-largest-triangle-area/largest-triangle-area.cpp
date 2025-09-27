class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        double x1,x2,x3,y1,y2,y3;    
       
       
        for(int i = 0;i<points.size()-2;i++){
            for(int j = i+1;j<points.size()-1;j++){
                for(int r = j+1;r<points.size();r++){
                        x1 = points[i][0];
                        y1 = points[i][1];
                        x2 = points[j][0];
                        y2 = points[j][1];
                        x3 = points[r][0];
                        y3 = points[r][1];
                     double area = 0.5 * abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)));
                    result  =max(result,area);
                }
            }
            
        }
        return result;
    }
};