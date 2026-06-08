// 1080. Insufficient Nodes in Root to Leaf Paths
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
    bool checkNodes(TreeNode* &root,int limit,int current){
        current+=root->val;
        if(root->left==nullptr&&root->right==nullptr){
            if(current<limit){
                root=nullptr;
                return true;
            }
            else {
                return false;
            }
        }
        bool left=true,right=true;
        if(root->left!=nullptr){
            left=checkNodes(root->left,limit,current);
        }
        if(root->right!=nullptr){
            right=checkNodes(root->right,limit,current);
        }
        if(left&&right){
            root=nullptr;
            return true;
        }
        return false;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        checkNodes(root,limit,0);
        return root;
    }
};