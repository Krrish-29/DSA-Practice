// 83. Remove Duplicates from Sorted List
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
            ListNode answerlist=NULL,*answer=&answerlist,*current=head;
            while(current!=NULL){
                if(current->next==NULL||current->val!=current->next->val){
                    answer->next=current;
                    current=current->next;
                    answer=answer->next;
                }
                else{
                    while(current->next!=NULL&&current->val==current->next->val){
                        current=current->next;
                    }
                }
            }
            return answerlist.next;
        }
    };