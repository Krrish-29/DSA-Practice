// 2096. Step-By-Step Directions From a Binary Tree Node to Another
class Solution {
private:
    TreeNode* getLca(TreeNode* root,int s,int d){
        if(root==nullptr||root->val==s||root->val==d){
            return root ;
        }
        TreeNode* left=getLca(root->left,s,d);
        TreeNode* right=getLca(root->right,s,d);
        if(left!=nullptr&&right!=nullptr){
            return root;
        }
        return left!=nullptr?left:right;
    }
    bool dfs(TreeNode* root,int target,string &path){
        if(root==NULL) return false;
        if(root->val==target) return true;
        path.push_back('L');
        if(dfs(root->left,target,path)) return true;
        path.pop_back();
        path.push_back('R');
        if(dfs(root->right,target,path)) return true;
        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // lca 
        // first get the lowest common ancestor then do dfs from it to both soruce and destination 
        // convert the string of source of U and add with dest path string from lca -> dest
        TreeNode* lca=getLca(root,startValue,destValue);
        string source,dest;
        dfs(lca,startValue,source);
        dfs(lca,destValue,dest);
        return string(source.size(),'U')+dest;
    }
};