class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(vector<int>& subset,vector<int>& nums,int i ){
        if(i==n){
            result.push_back(subset);
            return;
        }
        solve(subset,nums,i+1);
        subset.push_back(nums[i]);
        solve(subset,nums,i+1);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        n = nums.size();
        // vector<vector<int>> ans;
        // int n = nums.size();
        // int total = (1 << n);  // 2^n subset-үүд

        // for (int mask = 0; mask < total; mask++) {
        //     vector<int> sub;
        //     for (int i = 0; i < n; i++) {
        //         if (mask & (1 << i)) {  
        //             sub.push_back(nums[i]);
        //         }
        //     }

        //     ans.push_back(sub);
        // }
   
        // return ans;
        vector<int> subset;
        solve(subset,nums,0);
        // vector<int> S; 
        // P.push_back(S);
        
        // while (!X.empty()) {
        //     int f = X.front();
        //     X.erase(X.begin()); // remove first element
            
        //     int currentSize = P.size();
        //     for (int i = 0; i < currentSize; ++i) {
        //         vector<int> T = P[i]; // copy existing subset
        //         T.push_back(f);       // add the new element
        //         P.push_back(T);    // add the new subset
        //     }
        // }
        
        return result;
    }
};