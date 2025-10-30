class Solution {
public:
    unordered_map<int, string> urlMap;
    const string baseURL = "http://tinyurl.com/";
    int id = 1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urlMap[id] = longUrl;
        return baseURL + std::to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = std::stoi(shortUrl.substr(baseURL.size()));
        return urlMap[id];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));