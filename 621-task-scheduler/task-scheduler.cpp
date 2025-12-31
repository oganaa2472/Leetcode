class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);

        // 1. Давтамж тоолох
        for (char c : tasks)
            freq[c - 'A']++;

        // 2. Хамгийн их давтамж
        int maxFreq = *max_element(freq.begin(), freq.end());

        // 3. maxFreq-тэй task хэд байна
        int countMax = 0;
        for (int f : freq) {
            if (f == maxFreq)
                countMax++;
        }

        // 4. Формула
        int partCount = maxFreq - 1;
        int partLength = n + 1;
        int minIntervals = partCount * partLength + countMax;

        return max((int)tasks.size(), minIntervals);
    }
};