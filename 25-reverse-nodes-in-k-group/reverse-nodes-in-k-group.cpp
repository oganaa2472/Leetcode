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
    ListNode* getKth(ListNode* cur,int k){
        while(cur&&k>0){
            cur=cur->next;
            k--;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* dummy = new ListNode(0,head);
       ListNode* groupPrev = dummy;
        while(true){
            ListNode* kth = getKth(groupPrev,k);
            if(!kth){
                break;
            }
            ListNode* groupNext=kth->next;

            ListNode* prev = kth->next;
            ListNode* cur = groupPrev->next;
            while(cur!=groupNext){
                ListNode* tmp = cur->next;
                cur->next  = prev;
                prev = cur;
                cur = tmp;
            }
            ListNode* t = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = t;
        }
        return dummy->next;
    }
};