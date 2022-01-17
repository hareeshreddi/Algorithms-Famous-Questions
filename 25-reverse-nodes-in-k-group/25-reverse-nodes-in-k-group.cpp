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
    ListNode* reverseK(ListNode* head){
        ListNode* ans=NULL;
        while(head){
            ListNode* temp=head->next;
            head->next=ans;
            ans=head;
            head=temp;
        }
        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1) return head;
        ListNode* cur=head,*ans=NULL;
        int c=0;
        while(cur&&c<k-1){
            cur=cur->next;c++;
        }
        if(c==k-1&&cur){
            ListNode* next=reverseKGroup(cur->next,k);
            cur->next=NULL;
            ans=reverseK(head);
            head->next=next;
        }
        else return head;
        return ans;
    }
};