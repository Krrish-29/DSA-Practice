// 141. Linked List Cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*current=head;
        while(current){
            if(current->val==INT_MAX) return true;
            current->val=INT_MAX;
            current=current->next;
        }
        return false;
    }
};
