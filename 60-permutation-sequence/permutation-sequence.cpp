class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n, 1);
        vector<int> numbers;
        
        // 1. Precompute factorials up to (n-1)
        // 2. Fill the numbers list [1, 2, 3...n]
        for(int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        for(int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }

        // 3. Adjust k to be 0-indexed
        int kAdjust = k - 1;
        string result = "";

        // 4. Find digits one by one
        for(int i = n; i >= 1; i--) {
            int bucketSize = fact[i - 1];
            int index = kAdjust / bucketSize; // Use kAdjust here!
            
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            
            kAdjust %= bucketSize; // Update kAdjust for the next digit
        }
        return result;
    }
};