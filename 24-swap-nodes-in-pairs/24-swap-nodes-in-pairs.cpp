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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *h=head,*h1=head->next,*ans=h1;
        while(h&&h1){
            ListNode* temp=h1->next;
            if(temp && temp->next) h->next=temp->next;
            else h->next=temp;
            h1->next=h;
            if(!temp||!temp->next) return ans;
            h=temp;
            h1=h->next;
        }
        return ans;
    }
};