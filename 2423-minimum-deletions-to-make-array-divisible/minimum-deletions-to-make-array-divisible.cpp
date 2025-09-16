class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
       
        int n= nums.size();
        sort(numsDivide.begin(),numsDivide.end());
        int gcd = numsDivide[0];
        for(auto x:numsDivide){
            gcd = __gcd(x,gcd);
        }

        // if(gcd==1) return -1;
        sort(nums.begin(),nums.end());
        cout<<gcd;
        for(int i = 0;i<n;i++){
            if(gcd%nums[i]==0) return i;
        }
    
        return -1;
    }
};