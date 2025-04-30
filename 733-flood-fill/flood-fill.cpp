class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& image, int row, int col, int newColor, int origColor){

        if(row < 0 || col < 0 || row == image.size() || col == image[0].size() || image[row][col] != origColor) return;

        image[row][col] = newColor;

        dfs(image, row - 1, col,newColor, origColor);
        dfs(image, row + 1, col,newColor, origColor);
        dfs(image, row, col + 1,newColor, origColor);
        dfs(image, row, col - 1,newColor, origColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        // image[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();
        int origColor = image[sr][sc];
        
        if(color == origColor) return image;
        
        dfs(image,sr,sc,color,origColor);
        return image;
    }
};