class Solution {
public:
    vector<vector<int>> result;
    int k;

    void solve(int i ,int n,int sum,int num, vector<int>& ans){
        if(k==i){
            if(n==sum){
                result.push_back(ans);
            }
            return;
        }
        for(int j = num;j<=9;j++){
            ans.push_back(j);
            solve(i+1,n,sum+j,j+1,ans);
            ans.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        vector<int> answer;
        solve(0,n,0,1,answer);
        return result;
    }
};