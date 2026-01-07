// 1339. Maximum Product of Splitted Binary Tree
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
    unordered_map<TreeNode*,pair<int,int>>map;
    long long maxProd=LLONG_MIN;
    const int MOD=1e9+7;
    int getSum(TreeNode* root){
        int l=0,r=0;
        if(root->left!=NULL) l=getSum(root->left);
        if(root->right!=NULL) r=getSum(root->right);
        map[root]={l,r};
        return root->val+l+r;
    }
    void getProduct(TreeNode* root,int prev){
        int v=root->val+prev;
        int l=map[root].first;
        int r=map[root].second;
        maxProd=max({maxProd,(v+l)*1LL*r,(v+r)*1LL*l});
        if(root->left!=NULL) getProduct(root->left,v+r);
        if(root->right!=NULL) getProduct(root->right,v+l);
    }
public:
    int maxProduct(TreeNode* root) {
        getSum(root);
        getProduct(root,0);
        return maxProd%MOD;
    }
};
// without map normal recursion tree
// class Solution {
// private:
//     long long totalSum=0;
//     long long maxProd=LLONG_MIN;
//     const int MOD=1e9+7;
//     void getSum(TreeNode* root){
//         if(root==NULL) return ;
//         totalSum+=root->val;
//         getSum(root->left);
//         getSum(root->right);
//     }
//     long long getProduct(TreeNode* root){
//         if(root==NULL) return 0;
//         long long l = getProduct(root->left);
//         long long r = getProduct(root->right);
//         maxProd=max({maxProd,(totalSum-l)*l,(totalSum-r)*r});
//         return root->val+l+r;
//     }
// public:
//     int maxProduct(TreeNode* root) {
//         getSum(root);
//         getProduct(root);
//         return maxProd%MOD;
//     }
// };