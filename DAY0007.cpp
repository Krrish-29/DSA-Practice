// 61. Rotate List
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
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode*current=head;
            if(head==NULL) return head;
            int listsize=0;
            while(current!=NULL){
                current=current->next;
                listsize++;
            }
            current=head;
            if(k%listsize==0) return head;
            int x=listsize-k%listsize;
            while(--x>0){
                current=current->next;
            }
            ListNode*p1=current;
            while(current->next!=NULL){
                current=current->next;
            }
            current->next=head;
            head=p1->next;
            p1->next=NULL;
            return head;
        }
    };