// 1382. Balance a Binary Search Tree
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
    void getOrder(vector<int>&arr,TreeNode* root){
        if(root!=NULL) {
            getOrder(arr,root->left);
            arr.push_back(root->val);
            getOrder(arr,root->right);
        }
    }
    TreeNode* getTree(vector<int>&arr,int left,int right){
        if(left>right) return NULL;
        int mid=left+(right-left)/2;
        TreeNode *root=new TreeNode(arr[mid]);
        root->left=getTree(arr,left,mid-1);
        root->right=getTree(arr,mid+1,right);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        getOrder(arr,root);
        return getTree(arr,0,arr.size()-1);
    }
};