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
private:
    struct func{
        bool operator()( ListNode* &l1, ListNode* &l2){
            return l1->val>l2->val;
        }
    };
    priority_queue<ListNode*,vector<ListNode*>,func>pq;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=NULL,*start=NULL;
        for(auto l:lists){
            if(l!=NULL)
                pq.push(l);
        }
        while(pq.size()){
            ListNode* p=pq.top();pq.pop();
            if(ans==NULL) {
                ans=p;start=p;
            }
            else{
                ans->next=p;
                ans=p;
            }
            if(p->next)
                pq.push(p->next);
        }
        return start;
    }
};