// 199. Binary Tree Right Side View
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
    int maxH=-1;
    void traverse(TreeNode*root,int height,vector<int>&ans){
        if(root==NULL) return ;
        if(maxH<height) {
            ans.push_back(root->val);
            maxH=max(maxH,height);
        }
        traverse(root->right,height+1,ans);
        traverse(root->left,height+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        traverse(root,0,ans);
        return ans;
    }
};