// 1161. Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int maxSum=INT_MIN,level=0,currlevel=0;
        while(!q.empty()){
            int size=q.size();
            int currSum=0;
            currlevel++;
            while(--size>=0){
                currSum+=(q.front()->val);
                if(q.front()->left!=NULL) q.push(q.front()->left);
                if(q.front()->right!=NULL) q.push(q.front()->right);
                q.pop();
            }
            if(currSum>maxSum){
                level=currlevel;
                maxSum=currSum;
            }
        }
        return level;
    }
};