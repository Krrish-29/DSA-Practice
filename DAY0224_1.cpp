// 3217. Delete Nodes From Linked List Present in Array
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
    bool binary_search(vector<int>&nums,int target,int left,int right){
        int middle;
        while(left<=right){
            middle=left+(right-left)/2;
            if(nums[middle]==target) return true;
            else if(nums[middle]>target) right=middle-1;
            else left=middle+1;
        }
        return false;
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(),nums.end());
        ListNode *curr=new ListNode(0);
        ListNode *ans=curr;
        while(head!=NULL){
            if(!binary_search(nums,head->val,0,nums.size()-1)){
                curr->next=head;
                curr=curr->next;
            }
            head=head->next;
        }
        curr->next=NULL;
        return ans->next;
    }
};