class Solution {
public:
    vector<vector<int>> answer;

    void solve(int i,int n,int target,vector<int>& v,int cur){
        if(i>n||target<0) return;
        if(i==n){
            if(target==0) answer.push_back(v);
        }
        for(int dig = cur;dig<=9;dig++){
            if(target-dig>=0){
                v.push_back(dig);
                solve(i+1,n,target-dig,v,dig+1);
                v.pop_back();
            }
        }
       
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(0,k,n,v,1);
        return answer;
    }
};