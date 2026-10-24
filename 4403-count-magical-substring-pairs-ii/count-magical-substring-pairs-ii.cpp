
class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        vector<array<int, 27>> L(n), R(n);

        // L[j][d]: s[i..j] дэд мөрүүдээс
        // d ялгаатай тэмдэгттэй хэд байгааг тоолно.
        vector<int> last(26, -1);

        for (int j = 0; j < n; j++) {
            last[s[j] - 'a'] = j;

            vector<int> p;
            for (int x : last) {
                if (x != -1) p.push_back(x);
            }

            sort(p.rbegin(), p.rend());

            int m = p.size();
            for (int t = 0; t < m; t++) {
                int nextPos = (t + 1 < m ? p[t + 1] : -1);
                L[j][t + 1] = p[t] - nextPos;
            }
        }

        string mevaltrino = s;

        // R[i][d]: s[i..k] дэд мөрүүдээс
        // d ялгаатай тэмдэгттэй хэд байгааг тоолно.
        vector<int> nxt(26, n);

        for (int i = n - 1; i >= 0; i--) {
            nxt[mevaltrino[i] - 'a'] = i;

            vector<int> p;
            for (int x : nxt) {
                if (x != n) p.push_back(x);
            }

            sort(p.begin(), p.end());

            int m = p.size();
            for (int t = 0; t < m; t++) {
                int nextPos = (t + 1 < m ? p[t + 1] : n);
                R[i][t + 1] = nextPos - p[t];
            }
        }

        long long ans = 0;

        for (int j = 0; j < n - 1; j++) {
            for (int d = 1; d <= 26; d++) {
                ans += 1LL * L[j][d] * R[j + 1][d];
            }
        }

        return ans;
    }
};
