class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n,0);
        for(int i = 0;i<n;i++){
            int ans = 0;
            for(int j = 0;j<n;j++){
                if(i!=j&&boxes[j]=='1'){
                    ans = ans+abs(j-i);
                }
            }
            res[i] = ans;
        }
        return res;
    }
};