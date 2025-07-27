class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());

        vector<int> spf(max_val + 1);
        iota(spf.begin(), spf.end(), 0);

        for (int i = 2; i * i <= max_val; ++i)
            if (spf[i] == i)
                for (int j = i * i; j <= max_val; j += i) 
                    if (spf[j] == j) 
                        spf[j] = i;
                 

        unordered_map<int, vector<int>> pti;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            while (val > 1) {
                int p = spf[val];
                pti[p].push_back(i);
                while (val % p == 0) {
                    val /= p;
                }
            }
        }

        queue<pair<int, int>> q; 
        q.push({0, 0});

        unordered_set<int> vis;
        vis.insert(0);

        unordered_set<int> vp;

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == n - 1)
                return dist;

            for (int next : {curr - 1, curr + 1}) {
                if (next >= 0 && next < n && vis.find(next) == vis.end()) {
                    vis.insert(next);
                    q.push({next, dist + 1});
                }
            }

            int val = nums[curr];
            if (val > 1 && spf[val] == val && vp.find(val) == vp.end()) {
                for (int teleport_idx : pti[val]) {
                    if (vis.find(teleport_idx) == vis.end()) {
                        vis.insert(teleport_idx);
                        q.push({teleport_idx, dist + 1});
                    }
                }
                vp.insert(val);
            }
        }

        return -1;
    }
};