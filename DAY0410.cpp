// 1861. Rotating the Box
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>>mat(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[j][m-i-1]=boxGrid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            int limit=n-1;
            for(int i=n-1;i>=0;i--){
                if(mat[i][j]=='*') limit=i-1;
                else if(mat[i][j]=='#'){
                    mat[i][j]='.';
                    mat[limit][j]='#';
                    limit--;
                }
            }
        }
        return mat;
    }
};