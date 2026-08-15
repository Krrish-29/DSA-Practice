// 1886. Determine Whether Matrix Can Be Obtained By Rotation
class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n=mat.size();
        vector<vector<int>> matCopy(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matCopy[i][j]=mat[n-1-j][i];
            }
        }
        mat=matCopy;
    }
    bool check(vector<vector<int>>& mat,vector<vector<int>>& target){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int i=0;i<=4;i++){
            if(check(mat,target)) return true;
            rotate(mat);
        }
        return false;
    }
};