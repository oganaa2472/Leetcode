class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int LIMIT = 100001;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;
        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        parent.resize(LIMIT);
        size.resize(LIMIT, 1);
        for (int i = 0; i < LIMIT; i++)
            parent[i] = i;

        for (auto &num : nums) {
            int x = num;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    unite(num, i);
                    while (x % i == 0)
                        x /= i;
                }
            }
            if (x > 1) {
                unite(num, x);
            }
        }

        int leader = find(nums[0]);
        for (auto &x : nums) {
            if(x==1)
               return false;
            if (find(x) != leader)
                return false;
        }
        return true;
    }
};