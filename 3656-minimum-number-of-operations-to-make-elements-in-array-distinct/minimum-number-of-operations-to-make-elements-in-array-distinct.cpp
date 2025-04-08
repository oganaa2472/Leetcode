class Solution {
public:
    int minimumOperations(vector<int>& nums) {
    unordered_set<int> seen; 
    unordered_map<int,int> mp; 
       
    int i = 0;     
    int n = nums.size();
    for(int i = 0;i<n;i++){
        seen.insert(nums[i]);
        mp[nums[i]]++;
    }
    if(seen.size()==nums.size()) return 0;
    int operation= 0;
    while (i<nums.size()) {
      operation++;
      int size = min(i+3, (int)nums.size());
       for(int j = i;j<size;j++){
           if(mp[nums[j]]==1){
               mp.erase(nums[j]);
               seen.erase(nums[j]);
           }else{
               mp[nums[j]]--;
           }
       }
        i=size;
        // cout<<size<<endl;
        // cout<<nums.size()<<endl;
        // cout<<seen.size()<<endl;
        if(seen.size()==nums.size()-(size)){
            break;
        }
       
    }

    return operation;
    }
};