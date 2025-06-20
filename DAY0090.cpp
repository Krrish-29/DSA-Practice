// 112. Path Sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool sum(TreeNode*Node,int Sum,int &targetSum){
        if(!Node) return false;
        Sum+=Node->val;
        if(!Node->left&&!Node->right) return Sum==targetSum;
        return sum(Node->left,Sum,targetSum)||sum(Node->right,Sum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        bool ans= sum(root,0,targetSum);
        root->left=root->right=NULL;
        return ans;
        // if (root==NULL) return false;
        // queue<TreeNode*>queue;
        // root->val=targetSum-root->val;
        // queue.push(root);
        // while(!queue.empty()){
        //     int size=queue.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode*curr=queue.front();
        //         queue.pop();
        //         if(!curr->left&&!curr->right&&curr->val==0) return true;
        //         if(curr->left){
        //             curr->left->val=curr->val-curr->left->val;
        //             queue.push(curr->left);
        //         }
        //         if(curr->right){
        //             curr->right->val=curr->val-curr->right->val;
        //             queue.push(curr->right);
        //         }
        //     }
        // }
        // return false;
    }
};