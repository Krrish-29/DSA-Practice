// 3997. Count Dominant Nodes in a Binary Tree
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
    int dominantNodes(TreeNode* node,int& nodes){
        if(!node) return -1;
        int leftNodeValue = dominantNodes(node->left,nodes);
        int rightNodeValue = dominantNodes(node->right,nodes);
        if(node->val >= max(rightNodeValue,leftNodeValue)) nodes++;
        return max({node->val,rightNodeValue,leftNodeValue});
    }
public:
    int countDominantNodes(TreeNode* root) {
        int nodes=0;
        dominantNodes(root,nodes);
        return nodes;
    }
};