class Solution {
public:
    string convert(vector<int>&v){
        string s;
        for(int x:v) s += to_string(x)+',';
        return s;
    }
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        queue<pair<vector<int>, int>> q;
        

        q.push({nums1,0});
        
        unordered_set<string> visit;
        visit.insert(convert(nums1));

        while(!q.empty()){
            auto [cur,level] = q.front();
            q.pop();
            if(cur==nums2) return level;

            for(int l = 0;l<n;l++){
                for(int r = l;r<n;r++){
                    // choose hahah lol
                    vector<int> subarray(cur.begin()+l,cur.begin()+r+1);

                    vector<int> remain;
                    // remain
                    for(int i = 0;i<l;i++){
                        remain.push_back(cur[i]);
                    }
                    for(int i =r+1;i<n;i++){
                        remain.push_back(cur[i]);
                    }

                    // all possible position

                    for(int pos = 0;pos<=remain.size();pos++){
                        vector<int> next = remain;
                        next.insert(next.begin()+pos,subarray.begin(),subarray.end());
                        string key = convert(next);
                        if(!visit.count(key)){
                            visit.insert(key);
                            q.push({next,level+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};