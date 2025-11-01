class Solution {
public:
    ListNode* modifiedList(vector<int>& v, ListNode* head) {
        ListNode *d= new ListNode(-1);
        ListNode *t=d;
        set<int>s;
        for(auto i:v)
            s.insert(i);
        while(head!=NULL) {
            if(s.find(head->val)==s.end()) {
                t->next=head;
                t=t->next;
            }
            head=head->next;
        }
        t->next=NULL;
        return d->next;
    }
};