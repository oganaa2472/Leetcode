class Solution {
static bool comp(vector<int>& a , vector<int>& b)
{if(a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];  
}
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end() , comp);
        vector<int>ans;

        for(auto& e : envelopes)
        {
            if(ans.size() == 0 || e[1] > ans.back())
            {
                ans.push_back(e[1]);
            }
            else
            {
                int index = lower_bound(ans.begin() , ans.end() , e[1]) - ans.begin();
                ans[index] = e[1];
            }
        }
        return ans.size();
    }
};