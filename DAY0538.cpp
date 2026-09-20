// 2265. Count Nodes Equal to Average of Subtree
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
    int count=0;
    pair<int,int> helper(TreeNode* root){ // sum,nodes
        int totalSum=0,totalNodes=0;
        if(root->left!=nullptr){
            auto left=helper(root->left);
            totalSum+=left.first;
            totalNodes+=left.second;
        }
        if(root->right!=nullptr){
            auto right=helper(root->right);
            totalSum+=right.first;
            totalNodes+=right.second;
        }
        totalSum+=root->val;
        totalNodes++;
        if(root->val == totalSum/totalNodes) count++;
        return {totalSum,totalNodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        // at each point we need to know the number of nodes including the curret node and the sum of its subtree including itself , we can recursively go to the bottom and build up , at last only the root sum and 1 will be considered and then it would be returned to upper nodes which will add its current value and the other side sum and nodes , this will be done recursively 
        helper(root);
        return count;
    }
};