class Solution {
public:
    vector<int> prevSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> answer(n,-1);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty()&&nums[i]<nums[st.top()]){
                st.pop();
            }
            answer[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return answer;
    }

    vector<int> nextSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> answer(n,-1);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&&nums[i]<=nums[st.top()]){
                st.pop();
            }
            answer[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return answer;
    }
    int largestRectangleArea(vector<int>& heights) {
         
        int area = 0;
        int n = heights.size();
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);
        
         for (int i = 0; i < n; i++) {
             int left = i - prev[i];
             int right = next[i] - i;

            area = max(area,(heights[i]*(right+left-1)));
        }
        return area;
    }
};