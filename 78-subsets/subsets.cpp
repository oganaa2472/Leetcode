class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& X) {
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
        vector<vector<int>> P;
        vector<int> S; 
        P.push_back(S);
        
        while (!X.empty()) {
            int f = X.front();
            X.erase(X.begin()); // remove first element
            
            int currentSize = P.size();
            for (int i = 0; i < currentSize; ++i) {
                vector<int> T = P[i]; // copy existing subset
                T.push_back(f);       // add the new element
                P.push_back(T);    // add the new subset
            }
        }
        
        return P;
    }
};