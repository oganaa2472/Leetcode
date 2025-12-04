class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();

        unordered_map<int,int> prefix;
 
  
        for(auto log:logs){
            prefix[log[0]]++;
            prefix[log[1]]--;
        }
        int res = 0;
        int ans = -1;
        for(int i = 1950;i<=2050;i++){
            prefix[i] += prefix[i-1];
            if(res<prefix[i]){
                res = prefix[i];
                ans = i;
            }
        }
        return ans;
    }
};