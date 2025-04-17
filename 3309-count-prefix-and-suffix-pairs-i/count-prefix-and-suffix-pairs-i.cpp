struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntEndPrefix = 0;
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntEndPrefix++;
    }
    void decreaseEnd(){
        cntEndWith--;
    }
    void decreasePrefix(){
        cntEndPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntEndPrefix;
    }
};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Node* root = new Node();
       
        int count = 0;
        for(string& s : words){
            Node* node = root;
            int n = s.size();
            for(int i = 0;i<n;i++){
                
                if(!node->containKey(s[i])){
                    node->put(s[i],new Node());
                }
                node = node->get(s[i]);
                if(!node->containKey(s[n-1-i])){
                    node->put(s[n-i-1],new Node());
                }
                node = node->get(s[n-i-1]);
                count+=node->getPrefix();
            }   
            node->increasePrefix();
            
        }
        return count;
    }
};