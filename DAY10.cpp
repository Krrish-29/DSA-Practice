// 2. Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode answerlist;
    struct ListNode *answer=&answerlist;
    int carry=0;
    while(l1!=NULL&&l2!=NULL){
        if((l1->val+l2->val+carry)>=10){
            l1->val=(l1->val+l2->val+carry)-10;
            carry=1;
            answer->next=l1;
        }
        else{
            l1->val=(l1->val+l2->val+carry);
            carry=0;
            answer->next=l1;
        }
        answer=answer->next;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        if((l1->val+carry)>=10){
            l1->val=(l1->val+carry)-10;
            carry=1;
            answer->next=l1;
        }
        else{
            l1->val=(l1->val+carry);
            carry=0;
            answer->next=l1;
        }
        answer=answer->next;
        l1=l1->next;
    }
    while(l2!=NULL){
        if((l2->val+carry)>=10){
            l2->val=(l2->val+carry)-10;
            carry=1;
            answer->next=l2;
        }
        else{
            l2->val=(l2->val+carry);
            carry=0;
            answer->next=l2;
        }
        answer=answer->next;
        l2=l2->next;
    }
    if(carry==1){
        struct ListNode*newNode=(struct ListNode*)calloc(1,sizeof(struct ListNode));
        newNode->val=1;
        newNode->next=NULL;
        answer->next=newNode;
    }
    return answerlist.next;
}