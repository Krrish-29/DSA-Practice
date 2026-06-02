// 107. Binary Tree Level Order Traversal II
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
    void bfs(TreeNode* root,int level,vector<vector<int>>& ans){
        if(root==nullptr) return ;
        bfs(root->left,level-1,ans);
        bfs(root->right,level-1,ans);
        ans[level].push_back(root->val);
    }
    int getLevel(TreeNode* root,int level){
        if(root==nullptr) return level;
        return max(getLevel(root->left,level+1),getLevel(root->right,level+1));
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // level order O(n)
        int level=getLevel(root,0);
        vector<vector<int>>ans(level);
        bfs(root,level-1,ans);
        return ans;

        // queue O(n)
        queue<TreeNode*>q;
        if(root!=nullptr) q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()) {
            vector<int>temp;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto e=q.front();q.pop();
                temp.push_back(e->val);
                if(e->left!=nullptr){
                    q.push(e->left);
                }
                if(e->right!=nullptr){
                    q.push(e->right);
                }
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }    
};