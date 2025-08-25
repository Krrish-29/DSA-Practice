// 94. Binary Tree Inorder Traversal
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
private:
    void inorder(vector<int>&answer,TreeNode*root){
        if(root==NULL) return ;
        inorder(answer,root->left);
        answer.push_back(root->val);
        inorder(answer,root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        inorder(answer,root);
        return answer;
    }
};