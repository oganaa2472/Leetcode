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
    
class WordDictionary {
public:
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch:word){
            int i = ch- 'a';
            if(!node->children[i]){
                node->children[i] = new TrieNode();
            }   
            node = node->children[i];
        }
        node->isEnd=true;
    }
    bool searchUtil(TrieNode* n,string& word,int i){
        if(i==word.size()) return n->isEnd;
        bool matched = false;
        char ch = word[i];
        if(ch=='.'){
            for(int cur = 0;cur<26;cur++){
                if(n->children[cur]){
                   if(n->children[cur]&&searchUtil(n->children[cur],word,i+1)){
                    return true;
                   }
                }
            }
            return false;
        }else{
            int index = ch-'a';
            if(!n->children[index]){
                return false;
            }
            return searchUtil(n->children[index],word,i+1);
        }
    }
    bool search(string word) {
        return searchUtil(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */