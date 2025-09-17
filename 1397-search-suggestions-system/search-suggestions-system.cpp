   struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }

    };
    
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch-'a';
            if(!node->children[index]){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd=true;

    }

    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            
            node = node->children[index];
            
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
         TrieNode* node = root;
         for (char c : prefix) {
            int index = c - 'a';
        if (!node->children[index]) return false;
            
            node = node->children[index];
            
        }
        return true;
    }
    vector<string> getWords(string &prefix){
        TrieNode* node = root;
        vector<string> result;

        for(char c:prefix){
            if(!node->children[c-'a']){
                return result;
            }
            node = node->children[c-'a'];
        }
        dfs(node, prefix, result);
        return result;
    }
    void dfs(TrieNode* cur,string& word,vector<string>& result){

        if(result.size()==3) return;
        if(cur->isEnd){
            result.push_back(word);
        }
        for(char i = 'a';i<='z';i++){
            if(cur->children[i-'a']){
                word+= i;
                dfs(cur->children[i-'a'],word,result);
                word.pop_back();
            }
        }
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)   {
        Trie trie = Trie();
        for(string &w:products)
            trie.insert(w);

        vector<vector<string>> result;
        string prefix;
        for(auto ch:searchWord){
            prefix += ch;
            result.push_back(trie.getWords(prefix));
        }

        return result;
    }
};