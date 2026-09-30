class Solution {
public:
    int check(vector<int>& position, int m,int mid){
        int count = 1;               // Эхний бөмбөгийг position[0]-д тавина
        int last_pos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last_pos >= mid) {
                count++;
                last_pos = position[i];
            }
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = 1e9;
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if (check(position, m, mid)) {
                ans = mid;
                low = mid + 1;    // Илүү хол зайгаар байрлуулах боломжтой эсэхийг хайна
            } else {
                high = mid - 1;   // Зай хэтэрхий хол байна, багасгана
            }
        }
        return ans;
    }
};