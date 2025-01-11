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
    int length(ListNode* node){
        int len = 0;
        while(node!=NULL){
            len++;
            node = node->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = length(head);

        cout<<len<<endl;
        ListNode* temp = head;
        int pos=0;
        while(pos<(len)/2){
            temp = temp->next;
            pos++;
        }
        return temp;
    }
};