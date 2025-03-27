class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    vector<vector<char>> seats;
    bool isValid(int mask,vector<char> row){
        for (int i = 0; i < m; i++) {
            if ((mask & (1 << i)) && row[i] == '#') return false; 

            if ((mask & (1 << i)) && (i > 0) && (mask & (1 << (i-1)))) return false; // Adjacent seats can't both be occupied
        }
        return true;
    }
    bool isValidTransition(int prev,int mask){
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) { 
                if ((i > 0) && (prev & (1 << (i-1)))) return false; // Upper left diagonal
                if ((i < n-1) && (prev & (1 << (i+1)))) return false; // Upper right diagonal
            }
        }
        return true;
    }
    int solve(int row,int prev){
        if(row==n) return 0;
        if(dp[row][prev]!=-1) return dp[row][prev];
        int maxStudents = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            if(!isValid(mask,seats[row])) continue;
            if (!isValidTransition(prev, mask)) continue;
            maxStudents = max(maxStudents, __builtin_popcount(mask) + solve(row + 1, mask));

        }
        return dp[row][prev] = maxStudents;
    }
    int maxStudents(vector<vector<char>>& seats) {
        n = seats.size();
        m = seats[0].size();
        this->seats = seats;
        dp.assign(n, vector<int>(1 << m, -1));
        return solve(0,0);
    }
};