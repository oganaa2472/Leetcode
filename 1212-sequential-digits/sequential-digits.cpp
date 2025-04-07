class Solution {
public:
    vector<int> result; 
    void generateSequentialDigits(int currentNum, int lastDigit, int low, int high) {
    // If the current number exceeds the high limit, return
    if (currentNum > high) return;

    // If the current number is within the range, add it to the result
    if (currentNum >= low) {
        result.push_back(currentNum);
    }

    // Try to add the next digit in the sequence
    if (lastDigit < 9) {
        generateSequentialDigits(currentNum * 10 + lastDigit + 1, lastDigit + 1, low, high);
    }
}
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i <= 9; ++i) {
            generateSequentialDigits(i, i, low, high);
        }
        sort(result.begin(),result.end());
        return result;
    }
};