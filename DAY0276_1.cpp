// 328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd=new ListNode(0);
        ListNode *oddhead=odd;
        ListNode *even=new ListNode(0);
        ListNode *evenhead=even;
        while(head!=NULL){
            odd->next=head;
            odd=odd->next;
            head=head->next;
            even->next=head;
            even=even->next;
            if(head!=NULL) head=head->next;
        }
        if(even!=NULL) even->next=NULL;
        odd->next=evenhead->next;
        return oddhead->next;
    }
};