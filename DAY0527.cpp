// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // two possible answers are that store all cp (critical points) 
        // and make ans at last , or find ans while traversal 
        // for this we first need minDist and maxDist 
        // then we need to store first curr and just prev cp indices 
        // cause the maxDist will be found b/w firstcp and the last curr cp
        // and minDist will be found b/w just prev and curr cp
        // now for finding cp's 
        // we need 3 values -> prev curr and next
        // what they actually are -> prevPrev prev curr (due to linked list)
        // now while moving , first set curr and then prev after that we will have 3 variables to 
        // find if curr point(which is actually prev) is a cp or not 
        // if it is then store its idx accordingly 
        // else move the vars (just like sliding window)
        // if the cp is found we only initialize firstcp once and prevcp is updated after we have found firstcp and then again 
        // a new currcp and updating the distances
        int minDist=INT_MAX,maxDist=INT_MIN;
        int firstCp=-1,prevCp=-1,currCp=-1;
        int prev=-1,curr=-1,next=-1;
        int idx=0;
        while(head!=nullptr){
            next=head->val;
            if(curr==-1) curr=next;
            else if(prev==-1) {
                prev=curr;
                curr=next;
            }
            else{
                if((curr>next&&curr>prev)||(curr<next&&curr<prev)){
                    currCp = idx;
                    if(firstCp==-1) {
                        firstCp = currCp;
                        prevCp = currCp;
                    }
                    else{
                        minDist = min(minDist,currCp-prevCp);
                        maxDist = max(maxDist,currCp-firstCp);
                        prevCp = currCp;
                    }
                }
                prev=curr;
                curr=next;
            }
            head = head->next;
            idx++;
        }
        if(minDist==INT_MAX||maxDist==INT_MIN) return {-1,-1};
        return {minDist,maxDist};
    }
};