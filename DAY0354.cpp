// 894. All Possible Full Binary Trees
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
    map<pair<int,int>,vector<TreeNode*>>map;
    vector<TreeNode*> solve(int start,int end){
        if(start>end) return {NULL};
        if(start==end) return map[{start,end}]={new TreeNode(0)};
        if(map.find({start,end})!=map.end()) return map[{start,end}];
        vector<TreeNode*>roots;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=solve(start,i-1);
            vector<TreeNode*>right=solve(i+1,end);
            for(auto &L:left){
                for(auto &R:right){
                    TreeNode* root=new TreeNode(0);
                    if(L==NULL||R==NULL) continue;
                    root->left = L;
                    root->right = R;
                    roots.push_back(root);
                }
            }
        }
        return map[{start,end}]=roots;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(1,n);
    }
};