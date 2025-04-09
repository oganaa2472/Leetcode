class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> p;  
        for(int i = 0;i<n;i++){
            p.push_back({intervals[i][0],i});   
        }
        sort(p.begin(),p.end());
        
        vector<int> result(n,-1);

        for(int i = 0;i<n;i++){
            int cur = intervals[i][1];

            int left = 0;
            int right = p.size()-1;
            int ans = -1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(p[mid].first>=cur){
                    right = mid-1;
                    ans = p[mid].second;
                }else{
                    left = mid+1;
                  
                }
            }
            if(ans!=-1)
                result[i] = ans;
        }
        return result;

    }
};