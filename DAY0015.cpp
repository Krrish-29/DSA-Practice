// 82. Remove Duplicates from Sorted List II
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
            if(head==NULL||head->next==NULL) return head;
            ListNode answerlist(0);
            ListNode*answer=&answerlist,*current=head;
            while(current!=NULL){
                if(current->next==NULL||current->val!=current->next->val){
                    answer->next=current;
                    answer=answer->next;
                    current=current->next;
                }
                else{
                    int x=current->val;
                    while(current!=NULL&&(current->val==x)){
                        current=current->next;                
                    }
                }
            }
            answer->next=NULL;
            return answerlist.next;
        }
    };