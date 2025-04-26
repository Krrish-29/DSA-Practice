// 24. Swap Nodes in Pairs
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
            if(head==NULL||head->next==NULL) return head;
            ListNode answerlist,*answer=&answerlist,*current=head,*first,*second;
            while(current&&current->next){
                first=current;
                second=current->next;
                current=second->next;
                answer->next=second;
                second->next=first;
                answer=first;
            }
            answer->next=current;
            return answerlist.next;
        }
    };