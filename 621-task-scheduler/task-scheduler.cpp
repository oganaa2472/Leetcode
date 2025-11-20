class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequencyMap;
        
        // Step 1: Count the frequency of each task
        for (char task : tasks) {
            frequencyMap[task]++;
        }

        // Step 2: Initialize a max heap based on task frequencies
        priority_queue<int> maxHeap;
        for (auto& entry : frequencyMap) {
            maxHeap.push(entry.second);
        }

        // This queue will track tasks in their cooldown period
        queue<pair<int, int>> cooldownQueue;
        
        int time = 0;

        // Step 3: Simulate the time units
        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            time++;
            
            if (!maxHeap.empty()) {
                int currentTaskFreq = maxHeap.top() - 1;  // Execute task with max frequency
                maxHeap.pop();
                
                if (currentTaskFreq > 0) {
                    // Task needs to cool down before re-invoking
                    cooldownQueue.push({currentTaskFreq, time + n});
                }
            }

            // Step 4: Check cooldown queue if any task is ready to re-enter the max heap
            if (!cooldownQueue.empty() && cooldownQueue.front().second == time) {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return time;
    }
};