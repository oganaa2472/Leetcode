class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        int m = spells.size();
      
        vector<int> ans;
        
        for(int i = 0;i<m;i++){
            long long cur = spells[i];
            int a = n;
            int low = 0;
            int high = n-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                long long temp = cur*potions[mid];
                if(temp>=success){
                    a = mid;
                    high = mid -1;
                }else{
                    low = mid+1;
                }
            }
            if(a==n) ans.push_back(0);
            else ans.push_back(n-a);
        }
        return ans;
        
    }
};