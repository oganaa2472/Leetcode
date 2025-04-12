class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> books;
    int shelf;
    int n ;
    int solve(int i ,int remain,int maxHeight){
        if(i==n){
            return maxHeight;
        }
        if(dp[i][remain]!=-1) return dp[i][remain];
        
        vector<int> currentBook = books[i];
        int exclude = maxHeight + solve(i+1,shelf-currentBook[0],currentBook[1]);
        int include = INT_MAX;
        if(remain>=currentBook[0]){
            int maxHeightUpdated = max(maxHeight, currentBook[1]);
            include = solve(i+1,remain-currentBook[0],maxHeightUpdated);
        }
        return dp[i][remain] = min(include,exclude);
        
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    
        n = books.size();
        this->books = books;
        shelf = shelfWidth;
        dp.resize(n+1,vector<int>(shelfWidth+2,-1));
        return solve(0,shelfWidth,0);
    }
};