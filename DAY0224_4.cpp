// 2487. Remove Nodes From Linked List
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
private:
    // int maxVal=-1;
    // ListNode *ans;
    // void reverse(ListNode *head){
    //     if(head==NULL) return;
    //     reverse(head->next);
    //     if(head->val>=maxVal) {
    //         maxVal=head->val;
    //         ans=insertAtHead(ans,head->val);
    //     }
    // }
    // ListNode *insertAtHead(ListNode*curr,int ele){
    //     ListNode *temp=new ListNode(ele,curr);
    //     return temp;
    // }
    ListNode * reverseList(ListNode*head){
        ListNode *prev=NULL;
        while(head){
            ListNode *nextNode=head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        // reverse(head);
        // return ans;
        head=reverseList(head);
        ListNode *ans=NULL;
        int maxVal=-1;
        while(head){
            if(head->val>=maxVal){
                ListNode *nextNode=head->next;
                head->next=ans;
                ans=head;
                maxVal=head->val;
                head=nextNode;
            }
            else{
                head=head->next;
            }
        }
        return ans;
    }
};