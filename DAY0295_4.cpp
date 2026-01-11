// 865. Smallest Subtree with all the Deepest Nodes
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*>q;//for bfs
        q.push_back(root);

        unordered_map<TreeNode*,TreeNode*>map;//to get parents
        map[root]=NULL;

        unordered_set<TreeNode*>deepest;// to get lca

        int depth=0;
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*>newQ;
            deepest.clear();
            for(int i=0;i<size;i++){
                deepest.insert(q[i]);
                if(q[i]->left!=NULL) {
                    newQ.push_back(q[i]->left);
                    map[q[i]->left]=q[i];
                }
                if(q[i]->right!=NULL) {
                    newQ.push_back(q[i]->right);
                    map[q[i]->right]=q[i];
                }
            }
            depth++;
            q=newQ;
        }
        while(deepest.size()>1){
            unordered_set<TreeNode*>curr;
            for(auto node:deepest){
                curr.insert(map[node]);
            }
            deepest=curr;
        }
        return *deepest.begin();
    }
};