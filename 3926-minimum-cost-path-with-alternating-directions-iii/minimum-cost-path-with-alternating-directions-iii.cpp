class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        // dist[row][col][parity]
        vector<vector<vector<long long>>> dist(
            m,
            vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX))
        );

        // priority queue:
        // cost, row, col, parity
        priority_queue<
            tuple<long long,int,int,int>,
            vector<tuple<long long,int,int,int>>,
            greater<>
        > pq;


        // Start at (0,0)
        // pay entrance cost of (0,0)
        dist[0][0][1] = 1;

        pq.push({1, 0, 0, 1});


        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};


        while(!pq.empty()) {

            auto [cost, r, c, parity] = pq.top();
            pq.pop();


            if(cost != dist[r][c][parity])
                continue;


            // reached destination
            if(r == m-1 && c == n-1)
                return cost;


            int nextParity = parity ^ 1;


            // Try moving
            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];


                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;


                long long newCost = cost;


                // destination entrance cost
                newCost += (nr + 1) * (nc + 1);


                bool validMove = false;


                // odd action:
                // right or down
                if(parity == 1) {

                    if((nr == r && nc == c + 1) ||
                       (nr == r + 1 && nc == c))
                    {
                        validMove = true;
                    }

                }
                // even action:
                // left or up
                else {

                    if((nr == r && nc == c - 1) ||
                       (nr == r - 1 && nc == c))
                    {
                        validMove = true;
                    }
                }


                // illegal move
                if(!validMove) {
                    newCost += penalty[r][c];
                }


                if(newCost < dist[nr][nc][nextParity]) {

                    dist[nr][nc][nextParity] = newCost;

                    pq.push({
                        newCost,
                        nr,
                        nc,
                        nextParity
                    });
                }
            }


            // Wait action

            long long waitCost = cost + penalty[r][c];


            if(waitCost < dist[r][c][nextParity]) {

                dist[r][c][nextParity] = waitCost;

                pq.push({
                    waitCost,
                    r,
                    c,
                    nextParity
                });
            }
        }


        return -1;
    }
};