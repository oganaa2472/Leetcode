class Solution {
public:
    vector<int> arr;
    int k;
    int solve(int i,vector<int>& cache){
        if(i>=arr.size()) return 0;
        if(cache[i]!=-1) return cache[i];
        int res = 0,cur_max=0;
        for(int j = i;j<(int)min(k+i,(int)arr.size());j++){
            cur_max = max(arr[j],cur_max);
            int window_size = j - i + 1;
            res = max(res, solve(j + 1,cache) + cur_max * window_size);
          
        }
        return cache[i] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->arr = arr;
        this->k = k;
        vector<int> cache(arr.size() + 1, -1);
        cache[arr.size()] = 0;
        return solve(0,cache);
    }
};