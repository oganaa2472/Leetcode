class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
       priority_queue<int> pq; // min-heap
        int maxSize = 0;

        for (int num : nums) {
            if (pq.empty() || num >= pq.top()) {
                pq.push(num);
            }
            // Record max size of the priority queue
            maxSize = max(maxSize, (int)pq.size());
        }

        return maxSize;

        
    }
};
