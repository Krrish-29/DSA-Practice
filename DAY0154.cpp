// 1277. Count Square Submatrices with All Ones
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int maxSubmatrixSum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0&&j-1>=0&&matrix[i][j]!=0){
                    matrix[i][j]=1+min({matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]});
                }
                maxSubmatrixSum+=matrix[i][j];
            }
        }
        return maxSubmatrixSum;
    }
};