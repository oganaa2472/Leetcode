class Solution {
public:
    // represent a int by 32 bit vector
    int get(vector<int>& p){
        int res = 0;
        for(int i = 0;i<32;i++){
            if(p[i]>0){
                res|=(1<<i);
            }
        }
        return res;
    }
    void update(vector<int>& p,int val){
        for(int i =0;i<32;i++){
            if(val>>i & 1){
                p[i]++;
            }
        }
    }
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> p(32,0);
        int res = INT_MAX;
        for(int i = 0,j=0;i<nums.size();i++){
            update(p,nums[i]);
            res = min(res,abs(k-get(p)));
            while(j<i&&get(p)>=k){
                for(int t =0 ;t<32;t++){
                    if(nums[j]>>t&1) p[t]--;
                }
                int diff = abs(get(p)-k);
                if(diff==0) return 0;
                res = min(res,diff);
                j++;
            }
        }
        return res;
    }
};