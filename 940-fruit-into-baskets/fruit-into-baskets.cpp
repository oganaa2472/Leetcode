class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int>mp;
        int ans=0;
        int i=0, j=0;
        int n=arr.size();
        while(i<n){
            mp[arr[i]]++;
            while(mp.size()>2){
              mp[arr[j]]--;
              if(mp[arr[j]]==0)
                mp.erase(arr[j]);
              j++;
            } 
            
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};