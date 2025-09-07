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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy =new ListNode();
        ListNode* head = dummy;
        int extra = 0;
        while(l1!=NULL&&l2!=NULL){
            int val = l1->val + l2->val+ extra;
            int cur = val%10;
            extra = val/10;
            ListNode* newNode =new ListNode(cur);
            l1=l1->next;
            l2=l2->next;
            head->next = newNode;
            head = head->next;
        }
        while(l1!=NULL){
            int val = l1->val + extra;
            int cur = val%10;
            extra = val/10;
            ListNode* newNode =new ListNode(cur);
            l1=l1->next;
            head->next = newNode;
            head = head->next;
        }
        while(l2!=NULL){
            int val = l2->val + extra;
            int cur = val%10;
            extra = val/10;
            ListNode* newNode =new ListNode(cur);
            l2=l2->next;
            head->next = newNode;
            head = head->next;
        }
        if(extra>0){
            ListNode* newNode =new ListNode(extra);
            head->next = newNode;
        }
        return dummy->next;
    }
};