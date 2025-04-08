class Solution {
public:
    vector<int> batteries;
    int n;

    // Check if it's possible to run all n computers for 'mid' minutes
    bool check(long long mid) {
        long long total = 0;
        for (int i = 0; i < batteries.size(); i++) {
            total += min(mid, (long long)batteries[i]);
        }
        return total >= n * mid;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        this->batteries = batteries;
        this->n = n;

        // Sum all battery capacities safely
        long long totalPower = accumulate(batteries.begin(), batteries.end(), 0LL);

        // Binary search for max runtime
        long long left = 1;
        long long right = totalPower / n;
        long long answer = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};
