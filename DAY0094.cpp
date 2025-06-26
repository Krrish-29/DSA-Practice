// 143. Reorder List
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
    void reorderList(ListNode* head) {
        stack<ListNode*>stack;
        ListNode*current=head;
        int size=0;
        while(current){
            stack.push(current);
            current=current->next;
            size++;
        }
        ListNode*newList=head;
        ListNode*temp;
        size/=2;
        while(size--){
            temp=newList->next;
            newList->next=(ListNode*)stack.top();
            stack.pop();
            newList->next->next=temp;
            newList=temp;
        }
        newList->next=NULL;
    }
};