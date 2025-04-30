class Solution {
public:
    int findKthLargest(vector<int>& S, int k) {
         if (S.size() == 1) return S[0];

        // Step 1: Pick a random pivot
        srand(time(0));
        int pivot = S[rand() % S.size()];
        vector<int> L, E, G;
        // L is my smallest elements
        // E is pivot 
        // G is my biggest elements
        for (int num : S) {
            if (num < pivot) L.push_back(num);
            else if (num == pivot) E.push_back(num);
            else G.push_back(num);
        }
        if (k <= G.size()) {
            return findKthLargest(G, k);
        } else if (k <= G.size() + E.size()) {
            return pivot; // kth biggest is in E
        } else {
            return findKthLargest(L, k - G.size() - E.size());
        }
    //      if (k <= L.size()) {
    //     return quickSelect(L, k);
    // } else if (k <= L.size() + E.size()) {
    //     return pivot; // kth smallest is in E
    // } else {
    //     return quickSelect(G, k - L.size() - E.size());
    // }
}
};