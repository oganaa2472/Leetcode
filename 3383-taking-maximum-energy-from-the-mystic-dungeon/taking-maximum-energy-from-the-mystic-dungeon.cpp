class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int ans = INT_MIN;
        for(int i = energy.size()-1;i>energy.size()-1-k;i--){
            
            
            for(int j = i,sum = 0;j>=0;j=j-k){
                sum = sum + energy[j];
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};