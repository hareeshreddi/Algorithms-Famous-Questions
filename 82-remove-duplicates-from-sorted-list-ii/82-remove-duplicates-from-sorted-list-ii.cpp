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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *ans=NULL,*ans1=NULL;//ans for start of ans, ans1 is moving pointer
        while(head!=NULL){
            if(head->next!=NULL&&head->val==head->next->val){
                while(head->next!=NULL && head->val==head->next->val)
                    head->next=head->next->next;
                if(ans1) ans1->next=head->next;
            }
            else{
                if(ans==NULL) {ans=head;ans1=head;}
                else{
                    ans1->next=head;
                    ans1=head;
                }
            }
            head=head->next;
        }
        return ans;
    }
};