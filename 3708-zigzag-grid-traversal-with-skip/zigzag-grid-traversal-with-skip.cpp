class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
    vector<int> result;
    cout<<grid.size()<<" "<<grid[0].size();
    int m = grid[0].size();
    int leftToRight = 1; 
    int j = 0;
    for (int i = 0; i < grid.size(); ++i) {
        
        if(i%2==0){
            for(j = 0;j<grid[0].size();j=j+2){
                result.push_back(grid[i][j]);
            }
        }else if(m%2==1){
            for(j = grid[0].size()-2;j>=0;j=j-2){
                result.push_back(grid[i][j]);
            }
        }else{
            for(j = grid[0].size()-1;j>=0;j=j-2){
                result.push_back(grid[i][j]);
            }
        }
       

    
    }

    return result;
    }
};