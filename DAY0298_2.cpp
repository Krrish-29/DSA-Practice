// 987. Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0});
        vector<vector<int>>temp;
        int minCol=0,maxCol=0;
        while(!q.empty()){
            auto [node,row,col]=q.front();q.pop();
            temp.push_back({col,row,node->val});
            if(node->left!=NULL){
                q.push({node->left,row+1,col-1});
                minCol=min(minCol,col-1);
            }
            if(node->right!=NULL){
                q.push({node->right,row+1,col+1});
                maxCol=max(maxCol,col+1);
            }
        }
        vector<vector<int>>Tree(maxCol-minCol+1);
        sort(temp.begin(),temp.end());
        for(auto t:temp){
            Tree[t[0]-minCol].push_back(t[2]);
        }
        return Tree;
    }
};