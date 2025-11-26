class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        
        // Create an array to store the number of candies each child should get
        // Each child gets at least one candy.
        vector<int> candies(n, 1);
        
        // Traverse the ratings from left to right.
        for (int i = 1; i < n; i++) {
            // If the current child has a higher rating than the previous one
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            // If the current child has a higher rating than the next one
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Sum up candies
        return accumulate(candies.begin(), candies.end(), 0);
    }
};