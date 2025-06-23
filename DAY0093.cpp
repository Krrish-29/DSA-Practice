// 226. Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        vector<TreeNode*>queue;
        queue.push_back(root);
        while(!queue.empty()){
            int size=queue.size();
            for(int i=0;i<size;i++){
                TreeNode*current=queue[0];
                if(current&&current->left) queue.push_back(current->left);
                if(current&&current->right) queue.push_back(current->right);
                TreeNode*temp=current->left;
                current->left=current->right;
                current->right=temp;
                queue.erase(queue.begin());
            }
        }
        return root;
        // if(!root) return root;
        // queue<TreeNode*>queue;
        // queue.push(root);
        // while(!queue.empty()){
        //     int size=queue.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode*current=queue.front();
        //         queue.pop();
        //         TreeNode*temp=current->left;
        //         current->left=current->right;
        //         current->right=temp;
        //         if(current&&current->left) queue.push(current->left);
        //         if(current&&current->right) queue.push(current->right);
        //     }
        // }
        // return root;
    }
};