class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        set<int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp.insert(nums[i]);
        }
        int count = 1;
        int answer = 0;
        unordered_map<int,bool> check;
        for(auto& x:mp){
            if(mp.count(x+1)){
                count++;
            }else{
                count=1;
            }
            answer = max(answer,count);
        }
        // for(auto& [x,y]:mp){
        //     int count = 0;
        //     if(check[x]==false){
        //         int t = x;
        //         while(mp.count(t)>0){
        //             count++;
        //             check[t] =true;
        //             t++;
        //         }
        //         answer = max(answer,count);
        //     }
        // }
        return answer;
    }
};