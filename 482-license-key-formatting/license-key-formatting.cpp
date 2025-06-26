class Solution {
public:
   string licenseKeyFormatting(string s, int k) {
    string result;
    
    // 1. Бүх жижиг үсгийг том болгох, '-' хаях
    for (char c : s) {
        if (c != '-') {
            result += toupper(c);
        }
    }

    // 2. Ар талаас нь бүлэглэх
    string formatted;
    int count = 0;

    for (int i = result.size() - 1; i >= 0; --i) {
        if (count == k) {
            formatted += '-';
            count = 0;
        }
        formatted += result[i];
        count++;
    }

    // 3. Оруулсан string буруу дарааллаар байгаа тул эргүүлнэ
    reverse(formatted.begin(), formatted.end());

    return formatted;
}

};