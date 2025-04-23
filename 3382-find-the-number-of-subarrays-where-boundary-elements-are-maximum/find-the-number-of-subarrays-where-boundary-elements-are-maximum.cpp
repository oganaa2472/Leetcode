class Solution {
public:
    // vector<int> nextGreater;
    // unordered_map<int, vector<int>> indicesMap;
    //   int query(int ele, int L, int R) {
    //     int leftIndex = lower_bound(indicesMap[ele].begin(), indicesMap[ele].end(), L) - indicesMap[ele].begin();
    //     int rightIndex = lower_bound(indicesMap[ele].begin(), indicesMap[ele].end(), R) - indicesMap[ele].begin();
        
    //     if(rightIndex == indicesMap[ele].size())
    //         return rightIndex - leftIndex;
    //     if(indicesMap[ele][rightIndex] > R)
    //         return rightIndex - leftIndex;
    //     else
    //         return rightIndex - leftIndex + 1;
    // }

    unordered_map<int,vector<int>> indicesMap;
    vector<int> nextGreater;
    int query(int element,int l,int r){
        int leftIndex = lower_bound(indicesMap[element].begin(),indicesMap[element].end(),l) - indicesMap[element].begin();
        int rightIndex = lower_bound(indicesMap[element].begin(),indicesMap[element].end(),r) - indicesMap[element].begin();
    
        if(rightIndex == indicesMap[element].size())
            return rightIndex - leftIndex;
        if(indicesMap[element][rightIndex] > r)
            return rightIndex - leftIndex;
        else
            return rightIndex - leftIndex + 1;
    }
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        nextGreater.resize(n,n);
        stack<int> st;
        for(int i = 0;i<nums.size();i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
      
        long long count = 0;


        for(int i = 0;i<n;i++){
            indicesMap[nums[i]].push_back(i);
        }
        for(int i = 0;i<n;i++){
            int left = i;
            int right = nextGreater[i] - 1;
       
            count+= query(nums[i],left,right);
            indicesMap[nums[i]].erase(indicesMap[nums[i]].begin());
        }
        return count;
    //     int n = nums.size();
      
    //    nextGreater.resize(n, n);
    //     stack<int> st;
    //    for(int i = 0;i<nums.size();i++){
    //         while(!st.empty()&&nums[st.top()]<nums[i]){
    //             nextGreater[st.top()] = i;
    //             st.pop();
    //         }
    //         st.push(i);
    //    } 
    // for(int i = 0 ; i < n ; i++)
    //     indicesMap[nums[i]].push_back(i); 
      
    //    long long count = 0;
    //     for(int i = 0 ; i < n ; i++) {            
    //         int L = i;
    //         int R = nextGreater[i] - 1;   

    //         count += query(nums[i], L, R);            
    //     }
        
    //     return count;
    }
};