/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int i = 0;
        unordered_map<ListNode*,int> freq;
        ListNode* t = head;
        while(t!=NULL){
            freq[t]++;
            if(freq[t]>=2) return true;
            t = t->next;
        
        }
        return false;
    }
};