// 2196. Create Binary Tree From Descriptions
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int>seen;
        unordered_map<int,TreeNode*>map;
        for(auto &d:descriptions){
            seen.insert(d[0]);
            seen.insert(d[1]);
        }
        int parent,child;
        bool left;
        TreeNode* parentNode,* childNode;
        for(auto &d:descriptions){
            parent=d[0];
            child=d[1];
            left=d[2];
            if(map.find(parent)==map.end()) map[parent]=new TreeNode(parent);
            if(map.find(child)==map.end()) map[child]=new TreeNode(child);

            parentNode=map[parent];
            childNode=map[child];

            if(left) parentNode->left=childNode;
            else parentNode->right=childNode;

            seen.erase(child);
        }
        int rootVal=*(seen.begin());
        TreeNode* root=map[rootVal];
        return root;
    }
};