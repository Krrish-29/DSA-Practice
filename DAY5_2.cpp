// 19. Remove Nth Node From End of List
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode*counter=head;
            int count=0;
            while(counter!=NULL){
                count++;counter=counter->next;
            }
            delete(counter);
            if ((count-n)==0) {
                ListNode*temp=head;
                head=head->next;
                delete(temp);
                return head;
            }
            int x=count-n;
            ListNode*current=head;
            while(--x>0){
                current=current->next;
            }
            ListNode*temp=current;
            if(current->next==NULL) current->next=NULL;
            else current->next=current->next->next;
            return head;
        }
    };