struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        if (ch < 'a' || ch > 'z') return false;
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    void unsetEnd() {
        flag = false;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* node = root;
        for(int i = 0; i < word.length(); ++i) {
            if(!node->containsKey(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string &word) {
        Node* node = root;
        for(int i = 0; i < word.length(); ++i) {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool prefix(string &word) {
        Node* node = root;
        for(int i = 0; i < word.length(); ++i) {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return true;
    }
};

class Solution {
public:
    vector<string> ans;
    bool inBounds(int row, int col, int m, int n) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
    void dfs(int row, int col, vector<vector<char>>& board, 
    vector<string>& words, Node* node, string &temp) {
        char ch = board[row][col];
        if(!node->containsKey(ch)) return;
        node = node->get(ch);
        temp.push_back(ch);
        if(node->isEnd()) ans.push_back(temp), node->unsetEnd();
        board[row][col] = '#';
        int delta[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; ++i) {
            int nrow = row + delta[i];
            int ncol = col + delta[i + 1];
            if(inBounds(nrow, ncol, board.size(), board[0].size()) 
            && board[nrow][ncol] != '#') {
                dfs(nrow, ncol, board, words, node, temp);
            }
        }
        temp.pop_back();
        board[row][col] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie trie;
        for(auto word : words) trie.insert(word);
        string temp = "";
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(trie.root->containsKey(board[i][j]))
                    dfs(i, j, board, words, trie.root, temp);
            }
        }
        return ans;
    }
};