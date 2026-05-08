// 104. Maximum Depth of Binary Tree
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
    int maxLevel(int current,TreeNode* root){
        if(root==NULL) return current;
        return max(maxLevel(current+1,root->left),maxLevel(current+1,root->right));
    }
public:
    int maxDepth(TreeNode* root) {
        return maxLevel(0,root);
    }
};