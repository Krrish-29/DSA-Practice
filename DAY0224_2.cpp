// 203. Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr=new ListNode(0);
        ListNode *ans=curr;
        while(head!=NULL){
            if(head->val!=val){
                curr->next=head;
                curr=curr->next;
            }
            head=head->next;
        }
        curr->next=NULL;
        return ans->next;
    }
};