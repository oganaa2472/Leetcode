class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long long  n = arr.size();
        vector<int> copy = arr;
        sort(copy.begin(),copy.end());

        long long ans=0,prefix = 0, sorted=0;
        for(int i = 0;i<n;i++){
            sorted+=copy[i];
            prefix+=arr[i];
            if(sorted==prefix){
                ans++;
            }
        }
        return (int)ans;
    }
};