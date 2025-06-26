class Node{
    public:
        unordered_map<char,Node*> children;
};

class Trie{
    public:
        Node* root;
        Trie(){
            root = new Node();
        }
        void insert(string& word){
            Node* node = root;
            for(char c:word){
                if(node->children.find(c)==node->children.end()){
                    node->children[c] = new Node();
                }
                node = node->children[c];
            }
        }
        int lcp(string& word,int prefixLen){
            Node* node = root;
            int i = 0;
            while(i<min((int)word.size(),prefixLen)){
                if(node->children.find(word[i])==node->children.end())
                {
                    return i;
                }
                node = node->children[word[i]];
                i++;
            }
            return min((int)word.size(),prefixLen);
        }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini = 0;
        int n = strs.size();
        for(int i = 1;i<n;i++){
            if(strs[mini].size()>strs[i].size()){
                mini = i;
            }
        }
        Trie trie;
        trie.insert(strs[mini]);
        int prefixLen = strs[mini].size();
        for(int i = 0;i<n;i++){
            prefixLen = trie.lcp(strs[i],prefixLen);
        }
        return strs[mini].substr(0,prefixLen);

    }
};