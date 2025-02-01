class Solution {
public:
    void multiply(vector<vector<long> >& A,
              vector<vector<long> >& B)
{
    
    vector<vector<long> > C(3, vector<long>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j]
                    = (C[i][j] + ((A[i][k]) * (B[k][j])));
            }
        }
    }

    // Copy the result back to the first matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = C[i][j];
        }
    }
}
    vector<vector<long>> power(vector<vector<long>>m, int expo){
         vector<vector<long> > ans
        = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

   
        while (expo) {
            if (expo & 1)
                multiply(ans, m);
            multiply(m, m);
            expo >>= 1;
        }

    return ans;
        
    }

    int tribonacci(int n) {
         // base condition
    if (n == 0 || n == 1)
        return n;

    // Matrix M to generate the next tribonacci number
    vector<vector<long> > M
        = { { 1, 1, 1 }, { 1, 0, 0 }, { 0, 1, 0 } };

    // Since first 3 number of tribonacci series are:
    // trib(0) = 0
    // trib(1) = 1
    // trib(2) = 1
    // F = {{trib(2), 0, 0}, {trib(1), 0, 0}, {trib(0), 0,
    // 0}}
    vector<vector<long> > F
        = { { 1, 0, 0 }, { 1, 0, 0 }, { 0, 0, 0 } };

    vector<vector<long> > res = power(M, n - 2);
    multiply(res, F);

    return (long)res[0][0];
    }
};