// 1008. Construct Binary Search Tree from Preorder Traversal
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
        TreeNode* insert(TreeNode*root,int data){
            if(root==NULL){
                TreeNode*Node=(TreeNode*)malloc(sizeof(TreeNode));
                Node->left=NULL;
                Node->right=NULL;
                Node->val=data;
                return Node;
            }
            if(data>root->val){
                root->right = insert(root->right,data);
            }
            else if(data<root->val){
                root->left= insert(root->left,data);
            }
            return root;
        }
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            TreeNode *answer=NULL;
            for(int i=0;i<preorder.size();i++) answer=insert(answer,preorder[i]);
            return answer;
        }
    };