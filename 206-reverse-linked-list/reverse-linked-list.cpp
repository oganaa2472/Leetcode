/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void reverse(ListNode* head){
        if(head==NULL){
            return;
        }else{
            // ListNode* last = removeLastNode(head);
            // answer=last;

            
            
            // ListNode* t = a;


            
            reverse(head->next);
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* t = head;
        while(t!=NULL){
            ListNode* temp = t;
            t = t->next;
            temp->next = prev;
            prev = temp;
        }
        head = prev;
        return head;
    }
};