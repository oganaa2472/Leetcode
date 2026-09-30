class Solution {
public:
    bool check(const string& s, const string& p, const vector<int>& removable, int mid) {
        vector<bool> removed(s.size(), false);
        // Эхний mid ширхэг индексийг устгагдсанаар тэмдэглэнэ
        for (int i = 0; i < mid; i++) {
            removed[removable[i]] = true;
        }

        // Two Pointers: p нь s-ийн дэд дараалал мөн эсэхийг шалгана
        int p_idx = 0;
        for (int s_idx = 0; s_idx < s.size(); s_idx++) {
            if (removed[s_idx]) continue; // Устгагдсан тэмдэгтийг алгасна
            
            if (s[s_idx] == p[p_idx]) {
                p_idx++;
                if (p_idx == p.size()) return true; // p бүрэн олдлоо
            }
        }
        return p_idx == p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0;
        int high = removable.size();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(s, p, removable, mid)) {
                ans = mid;
                low = mid + 1;  // Хамгийн их k-г хайж байгаа тул утгыг ихэсгэнэ
            } else {
                high = mid - 1; // Устгасан тоо хэт ихэссэн тул багасгана
            }
        }

        return ans;
    }
};