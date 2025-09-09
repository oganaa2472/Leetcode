class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n, n);
        vector<int> prevSmaller(n, -1);
        stack<int> st;

        // Previous Smaller (left)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) prevSmaller[i] = st.top();
            st.push(i);
        }

        // clear stack for next loop
        while(!st.empty()) st.pop();

        // Next Smaller (right)
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) nextSmaller[i] = st.top();
            st.push(i);
        }

        int answer = 0;
        for(int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = heights[i] * width;
            answer = max(answer, area);
        }
        return answer;
    }
};
