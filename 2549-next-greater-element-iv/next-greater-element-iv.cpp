class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mid(n, vector<int>(0));
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                mid[i].push_back(st.top());
                st.pop();
            }
            st.push(i);
        }
        
        // vector<int> answer(n,-1);
        vector<int> right(n,-1);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i = 0;i<n;i++){
            while(!pq.empty()&&pq.top().first<nums[i]){
                right[pq.top().second] = nums[i];
                pq.pop();
            }
            for (int j : mid[i]) {
                pq.push({nums[j], j});
            }
        }
        return right;
    }
};