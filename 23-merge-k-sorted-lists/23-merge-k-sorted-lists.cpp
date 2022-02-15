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
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=NULL,*start=NULL;
        if(lists.size()==0) return ans;
        for(auto l:lists){
            if(l!=NULL)
                pq.push({l->val,l});
        }
        while(pq.size()){
            ListNode* p=pq.top().second;pq.pop();
            if(ans==NULL) {
                ans=p;start=p;
            }
            else{
                ans->next=p;
                ans=p;
            }
            if(p->next)
                pq.push({p->next->val,p->next});
        }
        return start;
    }
};