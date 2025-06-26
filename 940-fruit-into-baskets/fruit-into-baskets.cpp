class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int>mp;
        int ans=0;
        int i=0, j=0;
        int n=arr.size();
        while(i<n ){
            mp[arr[i]]++,i++;
            while(mp.size()>2){
              mp[arr[j]]--;
              if(mp[arr[j]]==0)
                mp.erase(arr[j]);
              j++;
            } 
            int c=0;
            ans=max(ans,i-j);
        }
        return ans;
    }
};