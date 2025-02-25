class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        vector<int> ans;

        for (int num : obstacles) {
            auto it = upper_bound(lis.begin(), lis.end(), num); 
            int index = it - lis.begin();

            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
            ans.push_back(index + 1);
        }
        return ans;
                
                
            
           
        
        return ans;
    }
};