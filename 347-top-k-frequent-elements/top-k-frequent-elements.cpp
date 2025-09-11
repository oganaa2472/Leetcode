class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         std::unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Step 2: Use a min-heap to keep the top k frequent elements.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

    for (auto& [num, freq] : frequencyMap) {
        minHeap.push({freq, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Step 3: Extract the elements from the heap.
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
    }
};