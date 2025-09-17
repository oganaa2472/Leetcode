class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    
    void insert(string& word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string& w : words) trie.insert(w);
        set<string> result;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        string path = "";
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, visited, i, j, trie.root, path, result);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             int i, int j, TrieNode* node, string& path, set<string>& result) {
        int m = board.size(), n = board[0].size();
        
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j])
            return;
        
        char c = board[i][j];
        int idx = c - 'a';
        if(!node->children[idx]) return; // No word with this prefix
        
        visited[i][j] = true;
        path.push_back(c);
        node = node->children[idx];
        
        if(node->isEnd) result.insert(path); // Found a word
        
        // Explore neighbors
        dfs(board, visited, i+1, j, node, path, result);
        dfs(board, visited, i-1, j, node, path, result);
        dfs(board, visited, i, j+1, node, path, result);
        dfs(board, visited, i, j-1, node, path, result);
        
        path.pop_back();
        visited[i][j] = false;
    }
};
