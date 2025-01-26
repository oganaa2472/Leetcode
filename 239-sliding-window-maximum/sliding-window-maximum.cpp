class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       
        map<int,int> mst;

        vector<int> answer(nums.size()-k+1,0);
        int j = 0;
        int i = 0;
        while(i<=nums.size()-k){
            while(j<k+i){
                mst[nums[j]]++;
                j++;
            }
            
            answer[i] = mst.rbegin()->first;
            mst[nums[i]]--;
            if(mst[nums[i]]==0) mst.erase(nums[i]);
            
            i++;

        }
        return answer;
    }
};