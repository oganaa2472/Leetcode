class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size(), neg = -1;
        
        for(int i = 0; i < n; i++) {
            if(balance[i] < 0) {
                neg = i;
                break;
            }
        }
        
        if(neg == -1) return 0;

        long long moves = 0;
        for(int dist = 1; dist < n; dist++) {
            for(int i : {(neg + n - dist) % n, (neg + dist) % n}) {
                int units = min(-balance[neg], balance[i]);
                moves += 1LL * units * dist;
                balance[i] -= units;
                balance[neg] += units;
            }
        }
        
        return balance[neg] == 0 ? moves : -1;
    }
};