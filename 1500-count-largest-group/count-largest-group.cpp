class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> umap;
        for(int i = 1;i<=n;i++){
            int k = i;
            int sum = 0;
            while(k>0){
                sum = sum + k%10;
                k = k / 10;
            }
            umap[sum]++;
        
        }
        int m = 0;
          unordered_map<int, int>::iterator itr;
         
          for (itr = umap.begin();itr != umap.end(); itr++)
          {
              if(itr->second>m){
                  m= itr->second; 
              }
         }
            int ans = 0;
          for (itr = umap.begin();
               itr != umap.end(); itr++)
          {
              if(m == itr->second){
                  ans++; 
              }
         }
        return ans;   
    }
};