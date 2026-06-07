// 113. Path Sum II
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
    vector<vector<int>>paths;
    void dfs(TreeNode* root,int current,int target,vector<int>& path){
        if(root==nullptr) return ;
        current+=root->val;
        path.push_back(root->val);
        if(current==target&&root->left==nullptr&&root->right==nullptr) paths.push_back(path);
        dfs(root->left,current,target,path);
        dfs(root->right,current,target,path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        dfs(root,0,targetSum,path);
        return paths;
    }
};