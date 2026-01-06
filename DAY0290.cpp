// 142. Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        // approach 1 hashmap O(n) space O(n) time
        // unordered_map<ListNode*,ListNode*>map;
        // while(head!=NULL){
        //     if(map.find(head)!=map.end()) return map[head];
        //     map[head]=head;
        //     head=head->next;
        // }
        // return NULL;

        // approach 2 slow & fast pointers O(1) space O(n) time 
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            } 
        }
        return NULL;
    }
};