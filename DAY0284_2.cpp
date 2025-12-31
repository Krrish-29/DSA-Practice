// 2130. Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
        int size=0;
        int ans=0;
        int i=-1;
        ListNode *curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        size/=2;
        curr=head;
        vector<int>sum(size,0);
        while(++i<size){
            sum[i]+=curr->val;
            curr=curr->next;
        }
        while(--i>=0){
            sum[i]+=curr->val;
            ans=max(ans,sum[i]);
            curr=curr->next;
        }
        return ans;
    }
};