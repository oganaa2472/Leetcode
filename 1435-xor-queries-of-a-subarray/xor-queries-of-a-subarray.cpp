class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);

      
        for (int i = 0; i < n; i++) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        vector<int> result;

       
        for (auto& q : queries) {
            int L = q[0], R = q[1];
            result.push_back(prefixXOR[R + 1] ^ prefixXOR[L]);
        }

        return result;

    }
};