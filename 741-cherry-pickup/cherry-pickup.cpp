#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    vector<vector<vector<int>>> memo;
    vector<vector<int>> grid;

    int dp(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2; 

        
        if (r1 >= N || c1 >= N || r2 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

       
        if (r1 == N - 1 && c1 == N - 1)
            return grid[r1][c1];

       
        if (memo[r1][c1][r2] != -1)
            return memo[r1][c1][r2];

       
        int cherries = grid[r1][c1];
        if (r1 != r2) 
            cherries += grid[r2][c2];

       
        int maxCherries = max({
            dp(r1 + 1, c1, r2 + 1), 
            dp(r1 + 1, c1, r2),     
            dp(r1, c1 + 1, r2 + 1), 
            dp(r1, c1 + 1, r2)      
        });

        return memo[r1][c1][r2] = cherries + maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        N = grid.size();
        memo = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, -1)));

        return max(0, dp(0, 0, 0));
    }
};
