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
        vector<int> answer(n,n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&&nums[i]<=nums[st.top()]){
                st.pop();
            }
            answer[i] =st.empty()?n:st.top();
            st.push(i);
        }
        return answer;
    }
      vector<int> prevGreater(vector<int>& nums){
        int n = nums.size();
        vector<int> answer(n,-1);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                st.pop();
            }
            answer[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return answer;
    }
    vector<int> nextGreater(vector<int>& nums){
        int n = nums.size();
        vector<int> answer(n,n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=nums[st.top()]){
                st.pop();
            }
            answer[i] =st.empty()?n:st.top();
            st.push(i);
        }
        return answer;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> prev = prevSmaller(nums);
        vector<int> next = nextSmaller(nums);
        vector<int> prevBig = prevGreater(nums);
        vector<int> nextBig = nextGreater(nums);
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res = (res - nums[i] * left * right);
        }
        for (int i = 0; i < n; i++) {
            long long left = i - prevBig[i];
            long long right = nextBig[i] - i;
            res = (res + nums[i] * left * right);
        }

        return res;

    }
};