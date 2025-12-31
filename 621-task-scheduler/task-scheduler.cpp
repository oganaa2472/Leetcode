class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks)
            freq[c - 'A']++;

        // Max heap of frequencies
        priority_queue<int> maxHeap;
        for (int f : freq)
            if (f > 0)
                maxHeap.push(f);

        // Queue for cooling tasks: {remaining count, time when available}
        queue<pair<int, int>> coolDown;

        int time = 0;

        while (!maxHeap.empty() || !coolDown.empty()) {
            time++;
            // Execute task if possible
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;

                if (cnt > 0) {
                    coolDown.push({cnt, time + n});
                }
            }

            // Check if any task finished cooling
            if (!coolDown.empty() && coolDown.front().second == time) {
                maxHeap.push(coolDown.front().first);
                coolDown.pop();
            }
        }

        return time;
    }
};
