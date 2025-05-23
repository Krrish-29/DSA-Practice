// 102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        if(!root) return answer;
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            vector<int>temp;
            int size=queue.size();
            for(int i=0;i<size;i++){
                TreeNode*node=queue.front();
                temp.push_back(node->val);
                queue.pop();
                if(node->left!=NULL) queue.push(node->left);
                if(node->right!=NULL) queue.push(node->right);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};