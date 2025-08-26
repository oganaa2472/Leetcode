class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double ans = 0;
        int a = 0;
        for(auto dim:dimensions){
            double x = dim[0]*dim[0];
            double y = dim[1]*dim[1];
            double sq =sqrt(double(x+y));
            if(ans<sq){
                ans = sq;
                a = (dim[0]*dim[1]);
            }
        }
        for(auto dim:dimensions){
            double x = dim[0]*dim[0];
            double y = dim[1]*dim[1];
            double sq =sqrt(double(x+y));
            if(ans==sq){
               
                a = max(dim[0]*dim[1],a);
            }
        }
        return a;
    }
};