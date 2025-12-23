// 2095. Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        int size=0;
        ListNode*curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        size/=2;
        if(size==0) return NULL;
        curr=head;
        while(curr!=NULL&&--size>0){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};