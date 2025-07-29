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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> list;
        ListNode* t = head;
        ListNode* t1 = head;
        while(t!=NULL){
            list.push_back(t->val);
            t=t->next;
        }
        vector<int> answer;
        int n = list.size();
        int size = n/k;
        cout<<size<<endl;
        for(int i = 0;i<size;i++){
            for(int j = k*(i+1)-1;j>=k*(i);j--){
                answer.push_back(list[j]);
            }
        }
        if(n%k!=0){
            for(int j = size*k;j<n;j++){
                answer.push_back(list[j]);
            }
        }
        ListNode* h = t1;
        for(auto a:answer){
            cout<<a;
            h->val = a;
            h = h->next;
        }
        return t1;
    }
};