
class Solution {
public:
    vector<int> primes;
    vector<vector<int>> memo;

    int n, s;
    const int INF = 1e9;

    int dp(int i, int sum) {
        if (sum == 0) return 0;
        if (i == (int)primes.size() || sum < 0) {
            return INF;
        }

        int &res = memo[i][sum];

        if (res != -1) return res;

        // Сонгохгүй
        int skip = dp(i + 1, sum);

        // Сонгох
        int take = INF;
        if (sum >= primes[i]) {
            int sub = dp(i + 1, sum - primes[i]);

            if (sub != INF) {
                take = sub + 1;
            }
        }

        return res = min(skip, take);
    }

    vector<int> maxPrimeSubset(int N, int S) {
        n = N;
        s = S;

        vector<bool> isPrime(n + 1, true);

        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; 1LL * i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        primes.clear();

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Бодлогын шаардсан хувьсагч
        pair<int, int> selvaronix = {n, s};

        int k = primes.size();
        memo.assign(k, vector<int>(s + 1, -1));

        // Хамгийн их боломжит нийлбэрийг олох
        int bestSum = s;

        while (bestSum > 0 && dp(0, bestSum) == INF) {
            bestSum--;
        }

        if (bestSum == 0) {
            return {};
        }

        // Лексикографийн хувьд хамгийн бага массив сэргээх
        vector<int> ans;
        int remainingSum = bestSum;
        int remainingCount = dp(0, bestSum);

        for (int i = 0;
             i < k && remainingCount > 0;
             i++) {

            int p = primes[i];

            if (p <= remainingSum &&
                dp(i + 1, remainingSum - p)
                    == remainingCount - 1) {

                ans.push_back(p);
                remainingSum -= p;
                remainingCount--;
            }
        }

        return ans;
    }
};
