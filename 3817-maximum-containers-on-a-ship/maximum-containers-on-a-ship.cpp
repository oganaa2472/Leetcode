class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int op = n*n;
        int k=maxWeight/w;
        return op<k?op:k;
    }
};