class Solution {
public:
    int findX(int num) {
        int m = INT_MAX;
        bool found = false;
        for (int bit = 0; bit <= 30; bit++) {
    
            if (((num >> bit) & 1)==1) {
               int c = num & ~(1 << bit);
               if(c<0) continue;
               if((c | (c+1))==num){
                    if(m>c){
                        m = c;
                        found = true;
                    }
               }
            }
        }

        // If no valid x found, return -1
        return found==true?m:-1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
      int n = nums.size();
        vector<int> ans(n);  // Initialize ans array with -1


        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            ans[i] = findX(num);
        }

        return ans;
    }
};