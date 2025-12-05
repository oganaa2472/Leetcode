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
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* dummy = head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        
        ListNode* prev = NULL;
        while(slow!=NULL){
            ListNode* temp = slow;
            slow=slow->next;
            temp->next = prev;
            prev = temp;
        }
        while(prev!=NULL){
            cout<<prev->val<<" ";
            if(dummy->val!=prev->val) return false;
            prev=prev->next;
            dummy=dummy->next;
        }
        
        return true;

    }
};